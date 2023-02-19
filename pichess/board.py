from pichess.square import Square
from PyQt6.QtWidgets import QWidget


class Board(QWidget):
    def __init__(self, parent):
        super().__init__(parent)
        self.setObjectName('board')

        # set squares
        for x in range(8):
            for y in range(8):
                Square(x, y, self)

        # set size
        self.resize(800, 800)
