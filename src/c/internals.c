#define PY_SSIZE_T_CLEAN
#include <Python.h>

// spam.system(s: str)
static PyObject *
Pin_execute(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);
}

static PyMethodDef Pin_Methods[] = {
    {"execute", Pin_execute, METH_VARARGS, "Тестовый метод"},
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
