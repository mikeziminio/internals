from internals import inspect_PyObject, inspect_PyVarObject

# print(execute("ls -la"))

class C:
    ...

s = C()

print("\n\n")
inspect_PyObject(s)
print("\n\n")
inspect_PyVarObject("abc")
print("\n\n")
inspect_PyVarObject((1, 2))