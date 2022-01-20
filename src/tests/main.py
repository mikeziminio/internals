from internals import execute, inspect_PyObject

# print(execute("ls -la"))

class C:
    ...

s = C()

inspect_PyObject(s)
