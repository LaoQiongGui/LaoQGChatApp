#include "Common.h"

QString toMd5(const QString &input) {
    QByteArray byteArray = input.toUtf8();
    QByteArray hash = QCryptographicHash::hash(byteArray, QCryptographicHash::Md5);
    return hash.toHex();
}
