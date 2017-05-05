#include <Python.h>
#include <stdio.h>

#define VERIFICA(obj)                                                          \
    do {                                                                       \
        if (obj == NULL) {                                                     \
            PyErr_Print();                                                     \
            exit(1);                                                           \
        }                                                                      \
    } while (0)

static PyModuleDef meu_modulo_def = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "meu_modulo",
    .m_doc = "Este é um módulo de exemplo para estender o Python",
    .m_size = -1, // Módulo global
};

PyMODINIT_FUNC PyInit_meu_modulo(void) // Necessário ter este nome
{
    PyObject *m;
    m = PyModule_Create(&meu_modulo_def);
    if (m == NULL)
        return NULL;
    return m;
}

/* vim ts=4:sw=4:et:st:si */
