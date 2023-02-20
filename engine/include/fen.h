#ifndef FEN_H
#define FEN_H

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> fen_to_dict (std::string fen);
std::unordered_map<std::string, char> fen_to_board (std::string fen);

#endif