from pichess.square import Square
from pichess.pieces import Piece
from PyQt6.QtWidgets import QWidget
import pichess_engine as engine


class Board(QWidget):
    def __init__(self, parent):
        super().__init__(parent)
        self.setObjectName('board')

        # set squares
        for x in range(8):
            for y in range(8):
                Square(x, y, self)

        # set starting position
        starting_fen = 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1'
        board_map = engine.fen_to_board(starting_fen)
        for coordinates, piece_letter in board_map.items():
            Piece.from_letter(piece_letter, coordinates, self)

        # set size
        self.resize(800, 800)


    def get_square_by_coordinates(self, coordinates):
        return self.findChild(Square, coordinates)
