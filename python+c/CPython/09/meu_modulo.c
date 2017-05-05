#include <Python.h>
#include <stddef.h>
#include <stdio.h>
#include <structmember.h>

#define VERIFICA(obj)                                                          \
    do {                                                                       \
        if (obj == NULL || PyErr_Occurred() != NULL) {                         \
            PyErr_Print();                                                     \
            return NULL;                                                       \
        }                                                                      \
    } while (0)

typedef struct {
    PyObject_HEAD;
    int x;
    PyObject *y;
} minha_classe_t;

static PyObject *minha_classe_new(PyTypeObject *tipo) {
    minha_classe_t *novo;
    printf("Chamando função new\n");
    novo = (minha_classe_t *)tipo->tp_alloc(tipo, 0);
    return (PyObject *)novo;
}

static int minha_classe_init(minha_classe_t *self, PyObject *args) {
    int x;
    PyObject *y;
    int estado;
    estado = PyArg_ParseTuple(args, "iO", &x, &y);
    if (!estado)
        return -1;
    self->x = x;
    self->y = y;
    Py_INCREF(self->y);
    return 0;
}

static PyObject *minha_classe_repr(minha_classe_t *self) {
    return PyUnicode_FromFormat("minha_classe: x = %d e y = %R",
                                self->x,
                                self->y);
}

static void minha_classe_del(minha_classe_t *self) {
    PyTypeObject *tipo;
    printf("Chamando função del\n");
    Py_XDECREF(self->y);
    tipo = (PyTypeObject *)PyObject_Type((PyObject *)self);
    tipo->tp_free(self);
    Py_XDECREF(tipo);
}

static PyMemberDef minha_classe_membros[] = {
    {
        .name = "x",
        .type = T_INT,
        .offset = offsetof(minha_classe_t, x),
        .flags = 1,
        .doc = "Inteiro da classe minha_classe"
    },
    {
        "y",
        T_OBJECT_EX,
        offsetof(minha_classe_t, y),
        0,
        "Objeto da classe minha_classe"
    },
    {NULL}
};

static PyTypeObject minha_classe = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "meu_modulo.minha_classe",
    .tp_basicsize = sizeof(minha_classe_t),
    .tp_new = (newfunc)minha_classe_new,
    .tp_init = (initproc)minha_classe_init,
    .tp_repr = (reprfunc)minha_classe_repr,
    .tp_dealloc = (destructor)minha_classe_del,
    .tp_members = minha_classe_membros,
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
