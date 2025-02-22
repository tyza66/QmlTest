#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cryptoopenssl.h"
#include "mycryptoutils.h"

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
    qmlRegisterType<MyCryptoUtils>("com.tyza66.crypto", 1, 0, "MyCryptoUtils");
    qmlRegisterType<CryptoOpenSSL>("com.openssl.crypto", 1, 0, "CryptoOpenSSL");
    engine.loadFromModule("openssl_example", "Main");

    return app.exec();
}
