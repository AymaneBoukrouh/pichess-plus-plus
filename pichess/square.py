from PyQt6.QtWidgets import QWidget, QFrame, QLabel, QGraphicsOpacityEffect
from PyQt6.QtCore import QRect, Qt


class Square(QFrame):
    def __init__(self, x, y, parent):
        super().__init__(parent)

        file_ = chr(ord('a') + x) # vertical columns, labeled a through h
        rank_ = 8-y # horizontal rows, labeled 1 through 8, starting from the bottom
        self.coordinates = f'{file_}{rank_}'

        self.setObjectName(self.coordinates)
        self.setGeometry(QRect(x*100, y*100, 100, 100))

        # set background color
        if x%2 == y%2:
            self.setProperty('color', 'light-square')
        else:
            self.setProperty('color', 'dark-square')
