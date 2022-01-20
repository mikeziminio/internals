#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "common.h"

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

static PyObject *
Pin_inspect_PyObject(PyObject *self, PyObject *args)
{
    PyObject* obj;

    if (!PyArg_ParseTuple(args, "O", &obj))
        return NULL;
    
    printf_bl("struct PyObject\n");
    printf_no("  ob_refcnt: %ld\n", obj->ob_refcnt);
    printf_no("  ob_type: %ld\n", (Py_ssize_t) obj->ob_type);
    printf_bl("  ⮩ struct PyObjectType\n");
    printf_gr("      <PyObject_VAR_HEAD>\n");
    printf_no("      ob_refcnt: %ld\n", obj->ob_type->ob_base.ob_base.ob_refcnt);
    printf_no("      ob_type: %ld\n", (Py_ssize_t) obj->ob_type->ob_base.ob_base.ob_type);
    printf_no("      ob_size: %ld\n", obj->ob_type->ob_base.ob_size);
    printf_gr("      </PyObject_VAR_HEAD>\n");
    printf_no("      tp_name: \"%s\"\n", obj->ob_type->tp_name);
    printf_gr("      /* For allocation */\n");
    printf_no("      tp_basicsize: %ld\n", obj->ob_type->tp_basicsize);
    printf_no("      tp_itemsize: %ld\n", obj->ob_type->tp_itemsize);
    printf_gr("      /* Methods to implement standard operations */\n");
    

    return PyLong_FromLong(1);
}

static PyMethodDef Pin_Methods[] = {
    {"execute", Pin_execute, METH_VARARGS, "Тестовый метод"},
    {"inspect_PyObject", Pin_inspect_PyObject, METH_VARARGS, "Исследовать объект как PyObject"},
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
