from PyQt6.QtWidgets import QWidget
from PyQt6.QtSvgWidgets import QSvgWidget


class Piece(QSvgWidget):
    piece_letter_map = {
      'King': 'K',
      'Queen': 'Q',
      'Rook': 'R',
      'Bishop': 'B',
      'Knight': 'N',
      'Pawn': 'P'
    }

    letter_piece_map = {v: k for k, v in piece_letter_map.items()}

    def __init__(self, coordinates, color, parent):
        super().__init__(parent)
        self.color = color

        if color:
            letter = self.letter.upper()
        else:
            letter = self.letter.lower()

        self.load(f'pichess/assets/svg/pieces/{letter}.svg')

        # resize and move
        self.resize(100, 100)
        self.set_coordinates(coordinates)

    def set_coordinates(self, coordinates):
        self.setObjectName(coordinates)
        self.coordinates = coordinates

        board = self.window().findChild(QWidget, 'board')
        square = board.get_square_by_coordinates(coordinates)
        x, y = map(int, (square.x(), square.y()))
        self.move(x, y)

    @staticmethod
    def from_letter(letter, coordinates, parent):
        color = letter.isupper() # color is white if letter is uppercase
        piece = Piece.letter_piece_map[letter.upper()]
        return globals()[piece](coordinates, color, parent)


# dynamically create chess pieces
for piece, letter in Piece.piece_letter_map.items():
    globals()[piece] = type(piece, (Piece,), {'letter': letter})
