#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "backend.h"

static QObject *GetBackend(QQmlEngine *engine, QJSEngine *scriptEngine)                 // 定义一个用于qmlRegisterSingletonType接收的回调。
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return Backend::instance();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    qmlRegisterSingletonType<Backend>("My.Backend", 1, 0, "Backend", GetBackend);       // 方法1，将后端单例注册到QML使用  适用于全局共享
    engine.rootContext()->setContextProperty("Backend2", new Backend2);                 // 方法2，将后端实例设置成QML的属性使用 可以灵活控制生命周期
    engine.loadFromModule("qmlandcpp", "Main");

    return app.exec();
}
