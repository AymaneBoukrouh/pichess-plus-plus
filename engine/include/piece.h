#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <string>

std::vector<std::string> filter_invalid_moves (std::vector<std::string> moves);
std::vector<std::string> king_moves (std::string coordinates);
std::vector<std::string> rook_moves (std::string coordinates);
std::vector<std::string> bishop_moves (std::string coordinates);
std::vector<std::string> queen_moves (std::string coordinates);
std::vector<std::string> knight_moves (std::string coordinates);
std::vector<std::string> light_pawn_moves (std::string coordinates);
std::vector<std::string> dark_pawn_moves (std::string coordinates);

#endif