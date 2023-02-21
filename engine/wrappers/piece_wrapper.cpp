#include <Python.h>
#include <string>
#include <vector>
#include "piece.h"
#include "piece_wrapper.h"

PyObject* _piece_moves (PyObject* self, PyObject* args, std::vector<std::string> (*piece_moves)(std::string)) {
  const char* coordinates;
  if (!PyArg_ParseTuple(args, "s", &coordinates))
    return NULL;
  
  std::vector<std::string> moves = piece_moves(coordinates);
  PyObject* py_moves = PyList_New(moves.size());

  for (int i=0; i<moves.size(); i++)
    PyList_SetItem(py_moves, i, PyUnicode_FromString(moves[i].c_str()));

  return py_moves;
}

extern PyObject* _king_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, king_moves);
}

extern PyObject* _rook_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, rook_moves);
}

extern PyObject* _bishop_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, bishop_moves);
}

extern PyObject* _queen_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, queen_moves);
}

extern PyObject* _knight_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, knight_moves);
}

extern PyObject* _light_pawn_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, light_pawn_moves);
}

extern PyObject* _dark_pawn_moves (PyObject* self, PyObject* args) {
  return _piece_moves(self, args, dark_pawn_moves);
}
