#include <Python.h>
#include <unordered_map>
#include <string>
#include "fen.h"
#include "fen_wrapper.h"

extern PyObject* _fen_to_dict (PyObject* self, PyObject* args) {
  const char* fen;
  if (!PyArg_ParseTuple(args, "s", &fen))
    return NULL;
  
  std::unordered_map<std::string, std::string> dict = fen_to_dict(fen);
  PyObject* py_dict = PyDict_New();

  for (auto it=dict.begin(); it!=dict.end(); ++it)
    PyDict_SetItemString(py_dict, it->first.c_str(), PyUnicode_FromString(it->second.c_str()));

  return py_dict;
}

extern PyObject* _fen_to_board (PyObject* self, PyObject* args) {
  const char* fen;
  if (!PyArg_ParseTuple(args, "s", &fen))
    return NULL;
  
  std::unordered_map<std::string, char> board = fen_to_board(fen);
  PyObject* py_board = PyDict_New();

  for (auto it=board.begin(); it!=board.end(); ++it)
    PyDict_SetItemString(py_board, it->first.c_str(), PyUnicode_FromString(std::string(1, it->second).c_str()));

  return py_board;
}
