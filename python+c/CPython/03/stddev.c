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
    modulo = PyImport_ImportModule("statistics");
    VERIFICA(modulo);

    PyObject *retorno =
        PyObject_CallMethod(modulo, "pstdev", "((iiii))", 10, 8, 9, 40);
    VERIFICA(retorno);
    double lat = PyFloat_AsDouble(retorno);
    printf("Desvio padrao %lg\n", lat);

    Py_XDECREF(retorno);
    Py_XDECREF(modulo);
    Py_Finalize();
    return 0;
}

/* vim ts=4:sw=4:et:st:si */
