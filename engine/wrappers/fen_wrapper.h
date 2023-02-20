#ifndef FEN_H
#define FEN_H

#include <Python.h>

PyObject* _fen_to_dict (PyObject* self, PyObject* args);
PyObject* _fen_to_board (PyObject* self, PyObject* args);

#endif