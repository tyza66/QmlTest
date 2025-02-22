#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>

class CryptoUtils : public QObject {
    Q_OBJECT
public:
    explicit CryptoUtils(QObject *parent = nullptr);

    Q_INVOKABLE QString md5(const QString &text);
};

#endif // CRYPTOUTILS_H
