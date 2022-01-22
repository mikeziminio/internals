#include "internals.h"

static PyMethodDef Pin_Methods[] = {
    {"inspect_PyObject", Pin_inspect_PyObject, METH_VARARGS, "Исследовать объект как PyObject"},
    {"inspect_PyVarObject", Pin_inspect_PyVarObject, METH_VARARGS, "Исследовать объект как PyVarObject"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef Pin_module = {
    PyModuleDef_HEAD_INIT,
    "internals",
    "internals - the researcher of the internals of python objects in your code",
    -1,
    Pin_Methods
};

PyMODINIT_FUNC PyInit_internals(void) {
    return PyModule_Create(&Pin_module);
}
