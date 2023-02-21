#ifndef PIECE_WRAPPER_H
#define PIECE_WRAPPER_H

#include <Python.h>

PyObject* _king_moves (PyObject* self, PyObject* args);
PyObject* _rook_moves (PyObject* self, PyObject* args);
PyObject* _bishop_moves (PyObject* self, PyObject* args);
PyObject* _queen_moves (PyObject* self, PyObject* args);
PyObject* _knight_moves (PyObject* self, PyObject* args);
PyObject* _light_pawn_moves (PyObject* self, PyObject* args);
PyObject* _dark_pawn_moves (PyObject* self, PyObject* args);

#endif