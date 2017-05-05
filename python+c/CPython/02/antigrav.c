#include <Python.h>
#include <stdio.h>

#define VERIFICA(obj)                                                          \
    do {                                                                       \
        if (obj == NULL) {                                                     \
            PyErr_Print();                                                     \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

int main(void) {
    PyObject *modulo;
    Py_Initialize();
    modulo = PyImport_ImportModule("modulo_inexistente");
    VERIFICA(modulo);
    Py_XDECREF(modulo);
    Py_Finalize();
    return 0;
}

/* vim ts=4:sw=4:et:st:si */
