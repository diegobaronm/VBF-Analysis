import os
import shutil
import argparse

def copy_pdfs(src_root, dst_root, allowed_dirs):
    """
    Recursively copy only PDF files and directory structure from selected top-level directories.
    """
    # Ensure destination exists
    os.makedirs(dst_root, exist_ok=True)

    for item in os.listdir(src_root):
        src_item = os.path.join(src_root, item)
        # Only process directories that are in the allowed list
        if os.path.isdir(src_item) and item in allowed_dirs:
            print(f"Processing directory: {item}")
            copy_dir_recursive(src_item, os.path.join(dst_root, item))
        else:
            # Skip anything else at the top level
            continue


def copy_dir_recursive(src_dir, dst_dir):
    """
    Recursively copy PDFs and directory structure from src_dir to dst_dir.
    """
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
                shutil.copy2(src_file, dst_file)


ALLOWED_DIRS = ['Zee','MuMu','Zll','TauTau','TauMu','EleTau','MuEle']

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Copy only selected directories containing PDF files.")
    parser.add_argument("source", help="Path to the source directory")
    parser.add_argument("destination", help="Path to the destination directory")

    args = parser.parse_args()

    copy_pdfs(args.source, args.destination, ALLOWED_DIRS)