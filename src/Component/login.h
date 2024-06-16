#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "../Common.h"

class Login : public QObject
{
    Q_OBJECT
public:
    explicit Login(QObject *parent = nullptr);

public slots:
    void submit(const QString &username, const QString &password);

signals:
};

#endif // LOGIN_H
