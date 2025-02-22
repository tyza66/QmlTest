#include "cryptoopenssl.h"
#include <openssl/evp.h>

CryptoOpenSSL::CryptoOpenSSL(QObject *parent) : QObject(parent) {
    // 构造函数实现（如果有需要）
}

QString CryptoOpenSSL::md5(const QString &text) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_md5();
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    EVP_DigestInit_ex(ctx, md, nullptr);
    EVP_DigestUpdate(ctx, text.toUtf8().data(), text.size());
    EVP_DigestFinal_ex(ctx, result, &result_len);
    EVP_MD_CTX_free(ctx);

    QString md5String;
    for (unsigned int i = 0; i < result_len; ++i) {
        md5String.append(QString::asprintf("%02x", result[i]));
    }

    return md5String;
}
