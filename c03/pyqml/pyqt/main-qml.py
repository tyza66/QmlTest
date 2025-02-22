import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtQml import *


class Backend(QObject):         # 创建一个继承自QObject的后端类
    message = pyqtSignal(str)   # 创建一个信号，用于发送消息

    @pyqtSlot(str)              # 创建一个槽，用于接收消息
    def receive(self, msg: str) -> None: # 槽函数
        self.message.emit(msg)  # 将接收到的消息返回回去


def GetBackend(engine: QQmlEngine, scriptEngine: QJSEngine) -> QObject: # 创建一个函数，用于返回后端对象
    backend = Backend()
    return backend


if __name__ == '__main__':
    app = QApplication(sys.argv)
    engine = QQmlApplicationEngine()
    url = QUrl("./main.qml")
    engine.objectCreated.connect(lambda obj, objUrl:
                                 sys.exit(-1)
                                 if not obj and url == objUrl
                                 else None)
    qmlRegisterSingletonType(Backend, "My.Backend", 1, 0, "Backend", GetBackend) # 注册单例类型到QML
    backend = Backend()
    engine.rootContext().setContextProperty("Backend2", backend)            # 将后端对象设置到QML上下文中
    engine.load(url)
    sys.exit(app.exec())