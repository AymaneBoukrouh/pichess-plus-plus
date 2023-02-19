#include <Python.h>

static PyMethodDef engineMethods[] = {
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef engineModule = {
  PyModuleDef_HEAD_INIT,
  "pichess_engine",
  "Pichess engine module.",
  -1,
  engineMethods
};

PyMODINIT_FUNC PyInit_pichess_engine (void) {
  return PyModule_Create(&engineModule);
};
