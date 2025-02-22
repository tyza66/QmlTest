#ifndef CRYPTOOPENSSL_H
#define CRYPTOOPENSSL_H

#include <QObject>
#include <QString>

class CryptoOpenSSL : public QObject {
    Q_OBJECT
public:
    explicit CryptoOpenSSL(QObject *parent = nullptr);

    Q_INVOKABLE QString md5(const QString &text);
};

#endif // CRYPTOOPENSSL_H
