from pichess.board import Board
from PyQt6.QtWidgets import QMainWindow, QWidget, QGridLayout


class MainWindow(QMainWindow):
    styles = 'pichess/assets/css/styles.css'

    def __init__(self):
        super().__init__()
        self.setWindowTitle('PiChess++')

        with open(self.styles) as f:
            self.setStyleSheet(f.read())

        centralWidget = CentralWidget(self)
        self.setCentralWidget(centralWidget)

        self.showMaximized()
  

class CentralWidget(QWidget):
    def __init__(self, parent):
        super().__init__(parent)

        self.layout = QGridLayout(self)
        self.layout.setSpacing(0)

        self.board = Board(self)
        self.board.setFixedSize(self.board.width(), self.board.height())

        self.layout.addWidget(self.board)
