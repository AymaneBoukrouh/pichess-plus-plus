#include <Python.h>
#include "fen_wrapper.h"
#include "piece_wrapper.h"

static PyMethodDef engineMethods[] = {
  {"fen_to_dict", _fen_to_dict, METH_VARARGS, "Converts a FEN string to a dictionary."},
  {"fen_to_board", _fen_to_board, METH_VARARGS, "Converts a FEN string to a board."},
  {"king_moves", _king_moves, METH_VARARGS, "Returns a list of all possible moves for a king."},
  {"rook_moves", _rook_moves, METH_VARARGS, "Returns a list of all possible moves for a rook."},
  {"bishop_moves", _bishop_moves, METH_VARARGS, "Returns a list of all possible moves for a bishop."},
  {"queen_moves", _queen_moves, METH_VARARGS, "Returns a list of all possible moves for a queen."},
  {"knight_moves", _knight_moves, METH_VARARGS, "Returns a list of all possible moves for a knight."},
  {"light_pawn_moves", _light_pawn_moves, METH_VARARGS, "Returns a list of all possible moves for a light pawn."},
  {"dark_pawn_moves", _dark_pawn_moves, METH_VARARGS, "Returns a list of all possible moves for a dark pawn."},
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
