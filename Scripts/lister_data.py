import os
import sys

## THIS SCRIPT MUST BE LAUNCHED AS

## python lister.py 1.NAME_SAMPLES 2.DIRECTORY_WHERE

def list(name,directory,counter):
    auxiliar_counter=0
    os.chdir(directory)
    for i in os.listdir():
            if i[-4:]=='root':
                print("'"+name+"_"+str(counter+auxiliar_counter)+"'"+":"+"'"+i+"'"+",")
                auxiliar_counter+=1
    os.chdir("../")
def data_combo(name,length):
    combo_list=[]
    for i in range(length):
        combo_list.append(name+"_"+str(i))
    print(combo_list)
    print("\n")
    print("\n")
    print("\n")
    return combo_list



def lister(sample):
    global c_2018
    global c_2017
    global c_2015
    os.chdir(sys.argv[1])
    a=os.listdir()
    counter=0
    if sample=="data_2018":
        print("#### DATA 2018")
        for dir in a:
            if ("data18" in dir) :#or ("data16" in dir):
                b=os.listdir(dir)
                list(sample,dir,counter)
                counter=counter+len(b)
        c_2018=counter
    elif sample=="data_2017":
        print("#### DATA 2017")
        for dir in a:
            if ("data17" in dir) :#or ("data16" in dir):
                b=os.listdir(dir)
                list(sample,dir,counter)
                counter=counter+len(b)
        c_2017=counter

    elif sample=="data_2015":
        print("#### DATA 2016 & 2015")
        for dir in a:
            if ("data15" in dir) or ("data16" in dir):
                b=os.listdir(dir)
                list(sample,dir,counter)
                counter=counter+len(b)
        c_2015=counter


years=["data_2018","data_2017","data_2015"]
for i in years:
    lister(i)

print("\n")
print("\n")

data_combo("data_2018",c_2018)
data_combo("data_2017",c_2017)
data_combo("data_2015",c_2015)

final_list=data_combo("data_2018",c_2018)+data_combo("data_2017",c_2017)+data_combo("data_2015",c_2015)
print(final_list)

print('\n')
os.chdir(sys.argv[1])
list_of_directories=[os.path.abspath(i)+'/' for i in os.listdir() if 'data' in i]
print(list_of_directories)
print(len(list_of_directories))