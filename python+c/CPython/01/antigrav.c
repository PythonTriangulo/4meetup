#include <Python.h>
#include <stdio.h>

int main(void) {
    PyObject *modulo;
    Py_Initialize();
    modulo = PyImport_ImportModule("antigravity");
    Py_XDECREF(modulo);
    Py_Finalize();
    return 0;
}

/* vim ts=4:sw=4:et:st:si */
