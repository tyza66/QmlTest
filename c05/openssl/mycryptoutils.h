#ifndef MYCRYPTOUTILS_H
#define MYCRYPTOUTILS_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>

class MyCryptoUtils : public QObject {
    Q_OBJECT
public:
    explicit MyCryptoUtils(QObject *parent = nullptr);

    Q_INVOKABLE QString md5(const QString &text);
};

#endif // MYCRYPTOUTILS_H
