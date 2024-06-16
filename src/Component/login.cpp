#include "login.h"

Login::Login(QObject *parent)
    : QObject{parent}
{
}

void Login::submit(const QString &username, const QString &password)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("http://localhost:12195/Auth/Login");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["username"] = username;
    json["password"] = toMd5(password);

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = manager->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 请求成功
            QByteArray response_data = reply->readAll();
            qDebug() << "Response:" << response_data;
        } else {
            // 请求失败
            qDebug() << "Error:" << reply->errorString();
        }
        reply->deleteLater();
    });
    return;
}
