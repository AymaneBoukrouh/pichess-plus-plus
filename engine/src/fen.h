#ifndef FEN_H
#define FEN_H

#include <Python.h>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> fen_to_dict (std::string fen);
PyObject* _fen_to_dict (PyObject* self, PyObject* args);

#endif