#include <vector>
#include <string>
#include "piece.h"

// utils
std::vector<std::string> filter_invalid_moves (std::vector<std::string> moves) {
    std::vector<std::string> valid_moves;

    for (std::string move: moves)
      if (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8')
        valid_moves.push_back(move);

    return valid_moves;
}

// king
std::vector<std::string> king_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves = {
    std::string(1, file-1) + std::string(1, rank+1), // top left
    std::string(1, file) + std::string(1, rank+1), // top
    std::string(1, file+1) + std::string(1, rank+1), // top right
    std::string(1, file-1) + std::string(1, rank), // left
    std::string(1, file+1) + std::string(1, rank), // right
    std::string(1, file-1) + std::string(1, rank-1), // bottom left
    std::string(1, file) + std::string(1, rank-1), // bottom
    std::string(1, file+1) + std::string(1, rank-1) // bottom right
  };

  return filter_invalid_moves(moves);
}

// rook
std::vector<std::string> rook_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves;

  for (int i=1; i<=8; i++) {
    moves.push_back(std::string(1, file) + std::to_string(i)); // vertical
    moves.push_back(std::string(1, 'a'+i-1) + std::string(1, rank)); // horizontal
  }

  return filter_invalid_moves(moves);
}

// bishop
std::vector<std::string> bishop_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves;

  for (int i=1; i<=8; i++) {
    moves.push_back(std::string(1, file+i-1) + std::to_string(rank+i-1)); // top right
    moves.push_back(std::string(1, file-i+1) + std::to_string(rank+i-1)); // top left
    moves.push_back(std::string(1, file+i-1) + std::to_string(rank-i+1)); // bottom right
    moves.push_back(std::string(1, file-i+1) + std::to_string(rank-i+1)); // bottom left
  }

  return filter_invalid_moves(moves);
}

// queen
std::vector<std::string> queen_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves;

  // TODO: use rook_moves and bishop_moves
  for (int i=1; i<=8; i++) {
    moves.push_back(std::string(1, file) + std::to_string(i)); // vertical
    moves.push_back(std::string(1, 'a'+i-1) + std::string(1, rank)); // horizontal
    moves.push_back(std::string(1, file+i-1) + std::to_string(rank+i-1)); // top right
    moves.push_back(std::string(1, file-i+1) + std::to_string(rank+i-1)); // top left
    moves.push_back(std::string(1, file+i-1) + std::to_string(rank-i+1)); // bottom right
    moves.push_back(std::string(1, file-i+1) + std::to_string(rank-i+1)); // bottom left
  }

  return filter_invalid_moves(moves);
}

// knight
std::vector<std::string> knight_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves = {
    std::string(1, file-1) + std::string(1, rank+2), // top left
    std::string(1, file+1) + std::string(1, rank+2), // top right
    std::string(1, file-2) + std::string(1, rank+1), // left top
    std::string(1, file+2) + std::string(1, rank+1), // right top
    std::string(1, file-2) + std::string(1, rank-1), // left bottom
    std::string(1, file+2) + std::string(1, rank-1), // right bottom
    std::string(1, file-1) + std::string(1, rank-2), // bottom left
    std::string(1, file+1) + std::string(1, rank-2) // bottom right
  };

  return filter_invalid_moves(moves);
}

// light pawn
std::vector<std::string> light_pawn_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves = {
    std::string(1, file) + std::string(1, rank+1), // forward
    std::string(1, file-1) + std::string(1, rank+1), // capture left
    std::string(1, file+1) + std::string(1, rank+1) // capture right
  };

  if (rank == '2') // double forward
    moves.push_back(std::string(1, file) + std::string(1, rank+2));

  return filter_invalid_moves(moves);
}

// dark pawn
std::vector<std::string> dark_pawn_moves (std::string coordinates) {
  char file = coordinates[0];
  char rank = coordinates[1];

  std::vector<std::string> moves = { std::string(1, file) + std::string(1, rank-1) };

  if (rank == '7')
    moves.push_back(std::string(1, file) + std::string(1, rank-2));

  return filter_invalid_moves(moves);
}
