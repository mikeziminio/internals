from sysconfig import get_config_var
from re import compile, findall 
from os import listdir
from os.path import isdir, join

python_include = get_config_var('INCLUDEPY')

objs: set = set()
types: set = set()

object_pattern = compile(r"[^\w](Py[a-zA-Z]+?Object)[^\w]")
type_pattern = compile(r"[^\w](Py[a-zA-Z]+?_Type)[^\w]")

def process_file(file_name):
    with open(file_name, "r") as f:
        content = f.read()
        fa = findall(object_pattern, content)
        objs.update(fa)
        # print(fa)
        fa = findall(type_pattern, content)
        types.update(fa)
        # print(fa)


def process_dir(root_path):
    paths = listdir(root_path)
    for p in paths:
        abs_path = join(root_path, p)
        if isdir(abs_path):
            process_dir(abs_path)
        else:
            process_file(abs_path)


def main():
    process_dir(python_include)

    li_types = sorted(list(types))
    li_objs = sorted(list(objs))

    for li_t in li_types:
        print(li_t)
    
    for li_o in li_objs:
        print(li_o)
    
    

main()
