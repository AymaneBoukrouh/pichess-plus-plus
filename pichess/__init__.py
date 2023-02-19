from PyQt6.QtWidgets import QMainWindow, QWidget


class MainWindow(QMainWindow):
    styles = 'pichess/assets/css/styles.css'

    def __init__(self):
        super().__init__()
        self.setWindowTitle('PiChess++')

        with open(self.styles) as f:
            self.setStyleSheet(f.read())

        centralWidget = QWidget(self)
        self.setCentralWidget(centralWidget)

        self.showMaximized()
  

class CentralWidget(QWidget):
    def __init__(self, parent):
        super().__init__(parent)
