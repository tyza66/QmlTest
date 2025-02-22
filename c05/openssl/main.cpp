#include <CryptoUtils.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

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

    qmlRegisterType<CryptoUtils>("com.tyza66.crypto", 1, 0, "CryptoUtils");
    engine.loadFromModule("openssl", "Main");

    return app.exec();
}
