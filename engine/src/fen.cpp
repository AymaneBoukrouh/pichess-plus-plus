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
