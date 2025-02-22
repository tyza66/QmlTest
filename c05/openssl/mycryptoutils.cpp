#include "mycryptoutils.h"

MyCryptoUtils::MyCryptoUtils(QObject *parent) : QObject(parent) {
    // 构造函数实现（如果有需要）
}

QString MyCryptoUtils::md5(const QString &text) {
    QByteArray hash = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5);
    return QString(hash.toHex());
}
