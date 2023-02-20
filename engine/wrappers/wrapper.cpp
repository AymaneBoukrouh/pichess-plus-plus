#include <Python.h>
#include "fen_wrapper.h"

static PyMethodDef engineMethods[] = {
  {"fen_to_dict", _fen_to_dict, METH_VARARGS, "Converts a FEN string to a dictionary."},
  {"fen_to_board", _fen_to_board, METH_VARARGS, "Converts a FEN string to a board."},
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
