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

std::unordered_map<std::string, char> fen_to_board (std::string fen) {
  std::string _string = fen_to_dict(fen)["string"];
  std::unordered_map<std::string, char> board;

  char x = 'a'; // file
  int y = 8; // rank

  for (char c: _string) {
    if (isalpha(c))
      board[std::string(1, x) + std::to_string(y)] = c;
    else if (isdigit(c))
      x += c - '0'; // increment x by the number of empty squares
    else if (c == '/')
      y--, x = 'a';
    if (!isdigit(c) && c != '/')
      x++;
  }

  return board;
}
