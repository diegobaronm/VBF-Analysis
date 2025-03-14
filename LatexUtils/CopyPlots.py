import os
import shutil
import argparse
import string

def copy_files(input_folder, output_folder, naming_scheme, mode, filter_str, remove_str):
    # Treat the filter and remove strings
    if filter_str=="":
        filter_str = 'pdf'
    else:
        filter_str = filter_str.split(',')
    if remove_str=="":
        remove_str = []
    else:
        remove_str = remove_str.split(',')

    all_pdf_files = [f for f in os.listdir(input_folder) if (f.endswith('.pdf') and all(i in f for i in filter_str) and not any(i in f for i in remove_str))]
    if len(all_pdf_files) == 0:
        print("No PDF files found in the input folder.")
        return

    print(f"Found {len(all_pdf_files)} PDF files in the input folder.")

    # Interactively select which files to copy
    print("Candidate files to copy:")
    for i, pdf_file in enumerate(all_pdf_files):
        print(f"{i+1}. {pdf_file}")

    indices = input("Enter the indices of the files to copy (comma-separated), enter 'all' to copy all : ")
    if indices.lower() == 'all':
        indices = ','.join([str(i+1) for i in range(len(all_pdf_files))])
    elif not all(i.isdigit() for i in indices.split(',')):
        print("Invalid input. Please enter comma-separated integers.")
        return
    else:
        indices = [int(i) for i in indices.split(',')]

    pdf_files = [all_pdf_files[i-1] for i in indices]
    
    print("Do you want to proceed with copying the following files? (yes/no): ")
    for i, pdf_file in enumerate(pdf_files):
        print(f"{i+1}. {pdf_file}")
    confirm = input()
    if confirm.lower() != 'yes':
        print("Operation cancelled.")
        return

    for i, pdf_file in enumerate(pdf_files):
        base_name = naming_scheme
        if mode == 'increment':
            new_name = f"{base_name}{i+1}.pdf"
        elif mode == 'alphabet':
            new_name = f"{base_name}{string.ascii_lowercase[i % 26]}.pdf"
        else:
            print("Invalid mode. Use 'increment' or 'alphabet'.")
            return

        src = os.path.join(input_folder, pdf_file)
        dst = os.path.join(output_folder, new_name)
        shutil.copy(src, dst)
        print(f"Copied {pdf_file} ---> {new_name}")

def check_to_prevent_override(destination_folder, naming_scheme):
    # Check the destination exists
    if not os.path.exists(destination_folder):
        print(f"Destination folder {destination_folder} does not exist.")
        create = input("Do you want to create it? (yes/no)")
        if create.lower() != 'yes':
            print("Operation cancelled.")
            exit(1)
        else:
            os.makedirs(destination_folder)
    
    # Check the contents of the folder to prevent overriding
    all_pdf_files = [f for f in os.listdir(destination_folder)]
    if any(naming_scheme in f for f in all_pdf_files):
        print(f"Some files with the naming scheme {naming_scheme} already exist in the destination folder.")
        print("Do you want to proceed and override them? (yes/no)")
        confirm = input()
        if confirm.lower() != 'yes':
            print("Operation cancelled.")
            exit(1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Copy PDF files with a specific naming scheme.")
    parser.add_argument("input_folder", help="The input folder containing PDF files.")
    parser.add_argument("output_folder", help="The output folder to copy PDF files to.")
    parser.add_argument("naming_scheme", help="The base naming scheme for the copied files.")
    parser.add_argument("mode", choices=['increment', 'alphabet'], help="The naming mode: 'increment' or 'alphabet'.")
    # Additional optional argument
    parser.add_argument("--select", help="Filter strings (comma-separated) used to select plots from the list.", type=str, default="", required=False)
    parser.add_argument("--remove", help="Filter strings (comma-separated) used to remove plots from the list.", type=str, default="", required=False)

    args = parser.parse_args()
    check_to_prevent_override(args.output_folder, args.naming_scheme)
    copy_files(args.input_folder, args.output_folder, args.naming_scheme, args.mode, args.select, args.remove)