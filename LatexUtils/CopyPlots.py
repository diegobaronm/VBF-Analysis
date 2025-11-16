import os
import shutil
import argparse

from ScrapLatexDoc import get_all_figure_paths

def copy_pdfs(src_root, dst_root, allowed_dirs, allowed_figures=None):
    """
    Recursively copy only PDF files and directory structure from selected top-level directories.
    """
    # Check allowed figures is provided
    if allowed_figures is None:
        print("No allowed figures provided. Exiting.")
        exit(1)

    # Ensure destination exists
    os.makedirs(dst_root, exist_ok=True)

    n_copied = 0
    for item in os.listdir(src_root):
        src_item = os.path.join(src_root, item)
        # Only process directories that are in the allowed list
        if os.path.isdir(src_item) and item in allowed_dirs:
            print(f"Processing directory: {item}")
            n_copied += copy_dir_recursive(src_item, os.path.join(dst_root, item), allowed_figures)
        else:
            # Skip anything else at the top level
            continue

    return n_copied


def copy_dir_recursive(src_dir, dst_dir, allowed_figures):
    """
    Recursively copy PDFs and directory structure from src_dir to dst_dir.
    """
    n_copied = 0
    for root, dirs, files in os.walk(src_dir):
        # Reconstruct the relative path
        rel_path = os.path.relpath(root, src_dir)
        dest_dir = os.path.join(dst_dir, rel_path)
        os.makedirs(dest_dir, exist_ok=True)
        
        # Copy PDF files
        for file in files:
            if file.lower().endswith(".pdf"):
                src_file = os.path.join(root, file)
                dst_file = os.path.join(dest_dir, file)
                if dst_file in allowed_figures:
                    #print("Copying...")
                    #print(f"  From: {src_file}")
                    #print(f"  To:   {dst_file}")
                    shutil.copy2(src_file, dst_file)
                    n_copied += 1
    return n_copied


ALLOWED_DIRS = ['Zee','MuMu','Zll','TauTau','TauMu','EleTau','MuEle','MjjRWStudies']

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Copy only selected directories containing PDF files.")
    parser.add_argument("source", help="Path to the source directory")
    parser.add_argument("latexDocPath", help="Path to the LaTeX document directory")
    parser.add_argument("--destination", help="Path to the destination directory inside the Latex document directory", default="analysisPlots")

    args = parser.parse_args()

    destination_path = os.path.join(args.latexDocPath, args.destination)

    # Obtain all the figures mentioned in the latex documents
    raw_figures_in_latex_docs = get_all_figure_paths(args.latexDocPath)
    # Add the full path to each figure and the .pdf extension
    figures_in_latex_docs_withpdf = [fig if fig.lower().endswith('.pdf') else fig+'.pdf' for fig in raw_figures_in_latex_docs]
    figures_in_latex_docs = [os.path.join(args.latexDocPath, fig) for fig in figures_in_latex_docs_withpdf]

    print("Number of figures referenced in LaTeX documents:", len(figures_in_latex_docs))
    
    n_figures_copied = copy_pdfs(args.source,
                                 destination_path,
                                 ALLOWED_DIRS,
                                 figures_in_latex_docs)
    
    print(f"Copied {n_figures_copied} PDF files to {destination_path}.")