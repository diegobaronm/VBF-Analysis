import os

def get_included_figure_paths(latex_doc_path):
    """
    Extracts the paths of all figures included in a LaTeX document.

    Args:
        latex_doc_path (str): Path to the LaTeX document.
    Returns:
        list: List of figure paths included in the document.
    """
    figure_paths = []
    with open(latex_doc_path, 'r') as file:
        for line in file:
            if '\\includegraphics' in line:
                # Extract the \includegraphics statement
                start_includegraphics = line.find('\\includegraphics')
                line = line[start_includegraphics:]
                start = line.find('{') + 1
                end = line.find('}')
                if start > 0 and end > start:
                    figure_path = line[start:end]
                    figure_paths.append(figure_path)
    return figure_paths

def get_all_tex_files(root_dir):
    """
    Recursively find all .tex files in the given directory.

    Args:
        root_dir (str): Root directory to search for .tex files.
    Returns:
        list: List of paths to .tex files.
    """
    tex_files = []
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.tex'):
                tex_files.append(os.path.join(dirpath, filename))
    return tex_files

def print_figure_paths(root_dir):
    """
    Print all figure paths included in LaTeX documents within the given directory.

    Args:
        root_dir (str): Root directory to search for .tex files.
    """
    all_figure_paths = {}
    tex_files = get_all_tex_files(root_dir)
    for tex_file in tex_files:
        figure_paths = get_included_figure_paths(tex_file)
        all_figure_paths[tex_file] = figure_paths

    print("Figures included in LaTeX documents:")
    for tex_file, figure_paths in all_figure_paths.items():
        if figure_paths!=[]:
            print(f"\nIn file: {tex_file}")
            for path in figure_paths:
                print(f"  - {path}")

def get_all_figure_paths(root_dir):
    """
    Get all figure paths included in LaTeX documents within the given directory.

    Args:
        root_dir (str): Root directory to search for .tex files.
    Returns:
        list: List of all figure paths.
    """
    all_figure_paths = []
    tex_files = get_all_tex_files(root_dir)
    for tex_file in tex_files:
        figure_paths = get_included_figure_paths(tex_file)
        all_figure_paths.extend(figure_paths)
    return all_figure_paths

def main():
    import os

    # Specify the root directory containing LaTeX documents
    root_dir = '/Users/user/Documents/HEP/ANA-STDM-2023-22-INT1'  # Change this to your directory

    # Print all figure paths
    print_figure_paths(root_dir)

if __name__ == "__main__":
    main()