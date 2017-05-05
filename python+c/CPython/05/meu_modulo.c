#include <Python.h>
#include <stdio.h>

#define VERIFICA(obj)                                                          \
    do {                                                                       \
        if (obj == NULL || PyErr_Occurred() != NULL) {                         \
            PyErr_Print();                                                     \
            return NULL;                                                       \
        }                                                                      \
    } while (0)

static PyObject *soma(PyObject *self, PyObject *args) {
    Py_ssize_t i, tamanho = PyTuple_Size(args);
    double acumulador = 0;
    for (i = 0; i < tamanho; ++i) {
        PyObject *obj;
        obj = PyTuple_GetItem(args, i);
        if (obj == NULL)
            return NULL;
        acumulador += PyFloat_AsDouble(obj);
        if (PyErr_Occurred() != NULL)
            return NULL;
    }
    return PyFloat_FromDouble(acumulador);
}

static PyMethodDef meu_modulo_metodos[] = {
    {
        .ml_name = "soma",
        .ml_meth = (PyCFunction)soma,
        .ml_flags = METH_VARARGS,
        .ml_doc = "Soma n valores"
    },
    {NULL}
};

static PyModuleDef meu_modulo_def = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "meu_modulo",
    .m_doc = "Este é um módulo de exemplo para estender o Python",
    .m_size = -1, // Módulo global
    .m_methods = meu_modulo_metodos};

PyMODINIT_FUNC PyInit_meu_modulo(void) // Necessário ter este nome
{
    PyObject *m;
    m = PyModule_Create(&meu_modulo_def);
    if (m == NULL)
        return NULL;
    return m;
}

/* vim ts=4:sw=4:et:st:si */
