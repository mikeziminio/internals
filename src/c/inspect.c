#include "internals.h"

int Pin_get_builtin_type_name(char* s, PyTypeObject* type, int with_eq)
{
    struct TypeMatching {
        PyTypeObject* ref;
        char* type_name_template;
    };
    
    struct TypeMatching tm[] = {
        
        // Числа
        {&PyLong_Type,  "%sPyLong_Type"},
        {&PyBool_Type,  "%sPyBool_Type"},
        {&PyFloat_Type, "%sPyFloat_Type"},

        // Строки и байты
        {&PyUnicode_Type, "%sPyUnicode_Type"},
        {&PyBytes_Type, "%sPyBytes_Type"},
        {&PyByteArray_Type, "%sPyByteArray_Type"},

        // Последовательности
        {&PyTuple_Type, "%sPyTuple_Type"},
        {&PyList_Type, "%sPyList_Type"},

        //Mapped
        {&PyDict_Type, "%sPyDict_Type"},

        {NULL, NULL}
    };

    for (int i = 0; tm[i].ref != NULL; i++) {
        if (type == tm[i].ref) {
           sprintf(s, tm[i].type_name_template, with_eq ? "== " : "");
           return 0;
        }
    }

    sprintf(s, "%s", "(not builtin type object)");
   
    return -1;
}

PyObject *
Pin_inspect_PyObject(PyObject *self, PyObject *args)
{
    PyObject* obj;

    if (!PyArg_ParseTuple(args, "O", &obj))
        return NULL;
    
    char s[100];
    Pin_get_builtin_type_name(s, obj->ob_type, 1);

    printf_bl("struct PyObject\n");
    printf_gr("  <PyObject_HEAD>\n");
    printf_no("  ob_refcnt: %ld\n", obj->ob_refcnt);
    printf_no("  ob_type: ref(%ld) %s\n", (Py_ssize_t) obj->ob_type, s);
    printf_gr("  </PyObject_HEAD>\n");
    printf_bl("  ob_type → struct PyObjectType\n");
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

PyObject *
Pin_inspect_PyVarObject(PyObject *self, PyObject *args)
{
    PyVarObject* obj;

    if (!PyArg_ParseTuple(args, "O", &obj))
        return NULL;
    
    char s[100];
    Pin_get_builtin_type_name(s, obj->ob_base.ob_type, 1);

    printf_bl("struct PyVarObject\n");
    printf_gr("  <PyObject_VAR_HEAD>\n");
    printf_no("  ob_refcnt: %ld\n", obj->ob_base.ob_refcnt);
    printf_no("  ob_type: ref(%ld) %s\n", (Py_ssize_t) obj->ob_base.ob_type, s);
    printf_no("  ob_size: %ld\n", (Py_ssize_t) obj->ob_size);
    printf_gr("  </PyObject_VAR_HEAD>\n");
    printf_bl("  ob_type → struct PyObjectType\n");
    printf_gr("      ...\n");
    printf_no("      tp_name: \"%s\"\n", obj->ob_base.ob_type->tp_name);
    
    return PyLong_FromLong(1);
}

PyObject *
Pin_inspect_PyLongObject(PyObject *self, PyObject *args)
{
    PyVarObject* obj;

    if (!PyArg_ParseTuple(args, "O", &obj))
        return NULL;
    
    char s[100];
    Pin_get_builtin_type_name(s, obj->ob_base.ob_type, 1);

    printf_bl("struct PyLongObject\n");
    printf_gr("  <PyObject_HEAD>\n");
    printf_no("  ob_refcnt: %ld\n", obj->ob_base.ob_refcnt);
    printf_no("  ob_type: ref(%ld) %s\n", (Py_ssize_t) obj->ob_base.ob_type, s);
    printf_gr("  </PyObject_HEAD>\n");
    printf_no("  ob_refcnt: %ld\n", obj->ob_base.ob_refcnt);
    printf_gr("  <_PyLongValue>\n");
        uintptr_t lv_tag; /* Number of digits, sign and flags */
    digit ob_digit[1];

    printf_gr("  </_PyLongValue>\n");
    printf_bl("  ob_type → struct PyObjectType\n");
    printf_gr("      ...\n");
    printf_no("      tp_name: \"%s\"\n", obj->ob_base.ob_type->tp_name);
    
    return PyLong_FromLong(1);
}