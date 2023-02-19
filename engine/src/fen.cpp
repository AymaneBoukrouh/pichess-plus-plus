#include <Python.h>
#include <unordered_map>
#include <sstream>
#include <string>
#include "fen.h"

std::unordered_map<std::string, std::string> fen_to_dict (std::string fen) {
  // TODO: check if fen is valid
  
  std::string _string, _turn, _en_passant, _halfmoves, _fullmoves;
  std::unordered_map<std::string, std::string> dict;

  std::stringstream ss(fen);
  ss >> _string >> _turn >> _en_passant >> _halfmoves >> _fullmoves;

  dict["string"] = _string;
  dict["turn"] = _turn;
  dict["en_passant"] = _en_passant;
  dict["halfmoves"] = _halfmoves;
  dict["fullmoves"] = _fullmoves;

  return dict;
}

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
