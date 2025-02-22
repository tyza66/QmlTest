

# 导入所需的模块
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout

# 创建QApplication实例
app = QApplication([])

# 创建一个主窗口
window = QWidget()
window.setWindowTitle('PyQt5 Window Example')
window.resize(400, 300)

# 创建一个垂直布局
layout = QVBoxLayout()

# 添加一个按钮到布局中
button = QPushButton('Click me!', window)
button.clicked.connect(lambda: print("Button clicked!"))
layout.addWidget(button)

# 将布局设置给主窗口
window.setLayout(layout)

# 显示窗口
window.show()

# 运行事件循环，等待用户操作
app.exec_()