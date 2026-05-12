#!/usr/bin/env python3
"""Generate LaTeX tables from fit-parameter text files.

The input format is the text output written by FitExperimentContainer in
Scripts/MjjFit.py. The script groups experiments by canonical region
(CRa, CRb, CRc, SR) and writes one LaTeX table per region plus a combined
file with all generated tables.
"""

from __future__ import annotations

import argparse
import math
import re
from dataclasses import dataclass
from pathlib import Path


# Formulas follow the model definitions in Scripts/MjjFit.py.
MODEL_INFO = {
	"linear_model": {
		"display_name": "Linear",
		"formula": r"$f(m_{jj}) = \mathrm{slope}\,m_{jj} + \mathrm{level}$",
		"parameter_names": ["slope", "level"],
	},
	"parabolic_model": {
		"display_name": "Parabolic",
		"formula": r"$f(m_{jj}) = a\,m_{jj}^{2} + b\,m_{jj} + c$",
		"parameter_names": ["a", "b", "c"],
	},
	"parabolic_cutoff_model": {
		"display_name": "Parabolic cutoff",
		"formula": (
			r"$f(m_{jj}) = a\,m_{jj}^{2} + b\,m_{jj} + c$ for "
			r"$m_{jj} \leq m_{\mathrm{cut}}$, constant above the cutoff"
		),
		"parameter_names": ["a", "b", "c"],
	},
	"exponential_model": {
		"display_name": "Exponential",
		"formula": r"$f(m_{jj}) = c - b\left(1 - e^{-a\,m_{jj}}\right)$",
		"parameter_names": ["a", "b", "c"],
	},
}

HEADER_PATTERN = re.compile(r"^#+\s*Experiment Name:\s*(.*?)\s*#+$")
FLOAT_PATTERN = re.compile(r"[-+]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][-+]?\d+)?")
FIELD_PREFIXES = [
	"Model",
	"Is cutoff model",
	"Cutoff value",
	"Parameters",
	"Covariance matrix",
	"Reduced Chi2",
	"X",
	"Y",
	"Y Uncertainty",
]
REGION_ORDER = ["CRa", "CRb", "CRc", "SR"]


@dataclass
class ExperimentRecord:
	name: str
	region_tag: str
	canonical_region: str
	ew_process: str
	qcd_process: str
	shape: str
	model_name: str
	is_cutoff_model: bool
	cutoff_value: float | None
	parameters: list[float]
	covariance_matrix: list[list[float]]
	reduced_chi2: float


def parse_arguments() -> argparse.Namespace:
	parser = argparse.ArgumentParser(
		description="Read MjjFit experiment files and generate LaTeX tables per region.",
	)
	parser.add_argument(
		"input_file",
		help="Path to a fit-results text file such as Fits_Zll_SherpaNLO.txt",
	)
	parser.add_argument(
		"--output-dir",
		default=str(Path(__file__).resolve().parent / "results"),
		help="Directory where the generated .tex files will be written.",
	)
	return parser.parse_args()


def split_into_blocks(file_contents: str) -> list[tuple[str, list[str]]]:
	blocks: list[tuple[str, list[str]]] = []
	current_name: str | None = None
	current_lines: list[str] = []

	for raw_line in file_contents.splitlines():
		header_match = HEADER_PATTERN.match(raw_line.strip())
		if header_match is not None:
			if current_name is not None:
				blocks.append((current_name, current_lines))
			current_name = header_match.group(1).strip()
			current_lines = []
			continue

		if current_name is not None:
			current_lines.append(raw_line.rstrip())

	if current_name is not None:
		blocks.append((current_name, current_lines))

	return blocks


def parse_block_fields(block_lines: list[str]) -> dict[str, str]:
	fields: dict[str, str] = {}
	current_key: str | None = None

	for raw_line in block_lines:
		line = raw_line.strip()
		if not line:
			continue

		next_key = next((key for key in FIELD_PREFIXES if line.startswith(f"{key}:")), None)
		if next_key is not None:
			current_key = next_key
			fields[current_key] = line.split(":", 1)[1].strip()
			continue

		if current_key is not None:
			fields[current_key] = f"{fields[current_key]} {line}".strip()

	return fields


def parse_float_list(raw_value: str) -> list[float]:
	return [float(token) for token in FLOAT_PATTERN.findall(raw_value)]


def parse_matrix(raw_value: str) -> list[list[float]]:
	row_matches = re.findall(r"\[([^\[\]]+)\]", raw_value)
	rows: list[list[float]] = []

	for row_match in row_matches:
		row = parse_float_list(row_match)
		if row:
			rows.append(row)

	if rows:
		return rows

	flat_values = parse_float_list(raw_value)
	if not flat_values:
		return []

	matrix_size = int(math.sqrt(len(flat_values)))
	if matrix_size * matrix_size != len(flat_values):
		return [flat_values]

	return [
		flat_values[index:index + matrix_size]
		for index in range(0, len(flat_values), matrix_size)
	]


def parse_experiment_name(experiment_name: str) -> tuple[str, str, str, str]:
	name_parts = experiment_name.split("_")
	if len(name_parts) != 4:
		raise ValueError(
			f"Experiment name '{experiment_name}' does not match the expected CR/SR_EWjj_QCDjj_shape pattern."
		)

	region_tag = name_parts[0]
	ew_process = name_parts[1].removeprefix("EWjj")
	qcd_process = name_parts[2].removeprefix("QCDjj")
	shape = name_parts[3]
	return region_tag, ew_process, qcd_process, shape


def canonicalise_region(region_tag: str) -> str:
	if region_tag.startswith("CRa"):
		return "CRa"
	if region_tag.startswith("CRb"):
		return "CRb"
	if region_tag.startswith("CRc"):
		return "CRc"
	if region_tag.startswith("SR"):
		return "SR"
	return region_tag


def parse_experiment_block(experiment_name: str, block_lines: list[str]) -> ExperimentRecord:
	fields = parse_block_fields(block_lines)
	region_tag, ew_process, qcd_process, shape = parse_experiment_name(experiment_name)

	model_name = fields["Model"]
	is_cutoff_model = fields["Is cutoff model"].strip().lower() == "true"
	cutoff_value = float(fields["Cutoff value"]) if "Cutoff value" in fields else None
	parameters = parse_float_list(fields["Parameters"])
	covariance_matrix = parse_matrix(fields["Covariance matrix"])
	reduced_chi2 = float(fields["Reduced Chi2"])

	return ExperimentRecord(
		name=experiment_name,
		region_tag=region_tag,
		canonical_region=canonicalise_region(region_tag),
		ew_process=ew_process,
		qcd_process=qcd_process,
		shape=shape,
		model_name=model_name,
		is_cutoff_model=is_cutoff_model,
		cutoff_value=cutoff_value,
		parameters=parameters,
		covariance_matrix=covariance_matrix,
		reduced_chi2=reduced_chi2,
	)


def parse_fit_file(input_path: Path) -> list[ExperimentRecord]:
	file_contents = input_path.read_text(encoding="utf-8")
	experiment_blocks = split_into_blocks(file_contents)
	if not experiment_blocks:
		raise ValueError(f"No experiment blocks were found in '{input_path}'.")

	return [parse_experiment_block(name, block_lines) for name, block_lines in experiment_blocks]


def latex_escape(text: str) -> str:
	escape_map = {
		"\\": r"\textbackslash{}",
		"&": r"\&",
		"%": r"\%",
		"$": r"\$",
		"#": r"\#",
		"_": r"\_",
		"{": r"\{",
		"}": r"\}",
		"~": r"\textasciitilde{}",
		"^": r"\^{}",
	}
	return "".join(escape_map.get(character, character) for character in text)


def format_number(value: float, significant_digits: int = 4) -> str:
	if value == 0:
		return "0"

	formatted = f"{value:.{significant_digits}g}"
	if "e" not in formatted and "E" not in formatted:
		return formatted

	coefficient, exponent = formatted.lower().split("e")
	return rf"{coefficient} \times 10^{{{int(exponent)}}}"


def parameter_names_for_model(model_name: str, n_parameters: int) -> list[str]:
	model_info = MODEL_INFO.get(model_name, {})
	parameter_names = model_info.get("parameter_names", [])
	if len(parameter_names) == n_parameters:
		return parameter_names

	return [rf"p_{{{index}}}" for index in range(n_parameters)]


def format_multiline_cell(lines: list[str]) -> str:
	return r"\begin{tabular}[t]{@{}l@{}}" + r" \\ ".join(lines) + r"\end{tabular}"


def format_model_cell(experiment: ExperimentRecord) -> str:
	model_info = MODEL_INFO.get(experiment.model_name)
	if model_info is None:
		return latex_escape(experiment.model_name)

	lines = [rf"\textbf{{{model_info['display_name']}}}", model_info["formula"]]
	if experiment.is_cutoff_model and experiment.cutoff_value is not None:
		lines.append(rf"$m_{{\mathrm{{cut}}}} = {format_number(experiment.cutoff_value)}$")

	return format_multiline_cell(lines)


def format_parameters_cell(experiment: ExperimentRecord) -> str:
	parameter_names = parameter_names_for_model(experiment.model_name, len(experiment.parameters))
	parameter_lines = [
		rf"${parameter_name} = {format_number(parameter_value)}$"
		for parameter_name, parameter_value in zip(parameter_names, experiment.parameters)
	]
	return format_multiline_cell(parameter_lines)


def format_covariance_matrix(matrix: list[list[float]]) -> str:
	if not matrix:
		return "N/A"

	n_columns = max(len(row) for row in matrix)
	alignment = "r" * n_columns
	row_strings = []
	for row in matrix:
		row_strings.append(" & ".join(format_number(value) for value in row))

	return (
		r"$\left(\begin{array}{" + alignment + r"}"
		+ r" \\ ".join(row_strings)
		+ r"\end{array}\right)$"
	)


def format_mc_combination(experiment: ExperimentRecord) -> str:
	return (
		rf"\textbf{{Selection:}} {latex_escape(experiment.region_tag)}; "
		rf"\textbf{{EWjj:}} {latex_escape(experiment.ew_process)}; "
		rf"\textbf{{QCDjj:}} {latex_escape(experiment.qcd_process)}"
	)


def table_caption(region: str, input_path: Path) -> str:
	return (
		f"Fit-model summary for {region} extracted from "
		rf"\texttt{{{latex_escape(input_path.name)}}}."
	)


def label_slug(input_path: Path, region: str) -> str:
	stem = re.sub(r"[^A-Za-z0-9]+", "-", input_path.stem).strip("-").lower()
	return f"tab:{stem}-{region.lower()}"


def render_region_table(region: str, experiments: list[ExperimentRecord], input_path: Path) -> str:
	lines = [
		f"% Auto-generated from {input_path.name} by LatexUtils/GenerateFitParamTables.py",
		r"\begin{table}[htbp]",
		r"\centering",
		rf"\caption{{{table_caption(region, input_path)}}}",
		rf"\label{{{label_slug(input_path, region)}}}",
		r"\small",
		r"\renewcommand{\arraystretch}{1.2}",
		r"\setlength{\tabcolsep}{6pt}",
		r"\begin{tabular}{p{0.24\textwidth} p{0.68\textwidth}}",
		r"\hline",
		r"\textbf{Quantity} & \textbf{Value} \\",
		r"\hline",
	]

	for index, experiment in enumerate(experiments):
		if index > 0:
			lines.append(r"\hline")

		lines.append(
			rf"\multicolumn{{2}}{{p{{0.92\textwidth}}}}{{\textbf{{{latex_escape(experiment.name)}}}}} \\")
		lines.append(rf"MC combination & {format_mc_combination(experiment)} \\")
		lines.append(rf"Model & {format_model_cell(experiment)} \\")
		lines.append(rf"Parameters & {format_parameters_cell(experiment)} \\")
		lines.append(rf"Covariance matrix & {format_covariance_matrix(experiment.covariance_matrix)} \\")
		lines.append(rf"Reduced $\chi^2$ & ${format_number(experiment.reduced_chi2, 5)}$ \\")

	lines.extend([
		r"\hline",
		r"\end{tabular}",
		r"\end{table}",
		"",
	])
	return "\n".join(lines)


def group_by_region(experiments: list[ExperimentRecord]) -> dict[str, list[ExperimentRecord]]:
	grouped_experiments = {region: [] for region in REGION_ORDER}
	for experiment in experiments:
		if experiment.canonical_region not in grouped_experiments:
			grouped_experiments[experiment.canonical_region] = []
		grouped_experiments[experiment.canonical_region].append(experiment)

	return {region: grouped_experiments[region] for region in grouped_experiments if grouped_experiments[region]}


def write_tables(experiments: list[ExperimentRecord], input_path: Path, output_dir: Path) -> list[Path]:
	output_dir.mkdir(parents=True, exist_ok=True)
	grouped_experiments = group_by_region(experiments)
	written_files: list[Path] = []
	combined_tables: list[str] = []

	for region in REGION_ORDER:
		region_experiments = grouped_experiments.get(region, [])
		if not region_experiments:
			continue

		table_text = render_region_table(region, region_experiments, input_path)
		region_output_path = output_dir / f"{input_path.stem}_{region}.tex"
		region_output_path.write_text(table_text, encoding="utf-8")
		written_files.append(region_output_path)
		combined_tables.append(table_text)

	combined_output_path = output_dir / f"{input_path.stem}_tables.tex"
	combined_output_path.write_text("\n".join(combined_tables), encoding="utf-8")
	written_files.append(combined_output_path)
	return written_files


def main() -> None:
	arguments = parse_arguments()
	input_path = Path(arguments.input_file).expanduser().resolve()
	output_dir = Path(arguments.output_dir).expanduser().resolve()

	if not input_path.is_file():
		raise FileNotFoundError(f"Input file '{input_path}' does not exist.")

	experiments = parse_fit_file(input_path)
	written_files = write_tables(experiments, input_path, output_dir)

	print(f"Read {len(experiments)} experiments from {input_path}.")
	print(f"Wrote {len(written_files)} LaTeX files to {output_dir}:")
	for written_file in written_files:
		print(f" - {written_file}")


if __name__ == "__main__":
	main()
