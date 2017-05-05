#include <Python.h>
#include <stdio.h>

#define VERIFICA(obj)                                                          \
    do {                                                                       \
        if (obj == NULL || PyErr_Occurred() != NULL) {                         \
            PyErr_Print();                                                     \
            return NULL;                                                       \
        }                                                                      \
    } while (0)

typedef struct {
    PyObject_HEAD;
} minha_classe_t;

static PyObject* minha_classe_new(PyTypeObject* tipo) {
    minha_classe_t *novo;
    printf("Chamando função new\n");
    novo = (minha_classe_t*)tipo->tp_alloc(tipo, 0);
    return (PyObject*) novo;
}

static PyTypeObject minha_classe = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "meu_modulo.minha_classe",
    .tp_basicsize = sizeof(minha_classe_t),
    .tp_new = (newfunc)minha_classe_new,
};

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
    if (0 != PyType_Ready(&minha_classe))
        return NULL;
    PyModule_AddObject(m, "minha_classe", (PyObject *)&minha_classe);
    return m;
}

/* vim ts=4:sw=4:et:st:si */
