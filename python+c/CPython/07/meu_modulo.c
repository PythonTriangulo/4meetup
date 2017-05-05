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

static PyObject *primeiros(PyObject *self, PyObject *args, PyObject *kwdict) {
    const char *str;
    int tamanho_str;
    int cortador = 1;
    char *keywords[] = {"string", "cortador", NULL};
    int estado = PyArg_ParseTupleAndKeywords(args, kwdict, "s#|i", keywords,
                                             &str, &tamanho_str, &cortador);
    if (!estado)
        return NULL;
    if (cortador > tamanho_str) {
        PyErr_SetString(PyExc_ValueError, "Não dá para aumentar a string");
        return NULL;
    }
    return Py_BuildValue("s#", str, cortador);
}

static PyMethodDef meu_modulo_metodos[] = {
    {
        .ml_name = "soma",
        .ml_meth = (PyCFunction)soma,
        .ml_flags = METH_VARARGS,
        .ml_doc = "Soma n valores"
    },
    {
        "primeiros",
        (PyCFunction)primeiros,
        METH_VARARGS | METH_KEYWORDS,
        "Retorna os primeiros n caracteres de uma string"
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
