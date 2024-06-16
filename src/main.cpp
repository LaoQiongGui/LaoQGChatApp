#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickWindow>

#include "Component/login.h"
#include "Component/chat.h"
#include "Component/Chat/sessionarea.h"

void registerHandlers();

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    registerHandlers();

    QQmlEngine eng;
    eng.addImportPath("qrc:/");

    QQmlComponent com(&eng);
    com.loadUrl(QUrl("qrc:/main.qml"));
    if (com.isError()) {
        qDebug() << com.errorString();
    }

    std::unique_ptr<QQuickWindow> comwin(static_cast<QQuickWindow *>(com.create()));
    comwin->setTitle("LaoQGChatApp");
    comwin->setVisible(true);
    comwin->show();

    return app.exec();
}

void registerHandlers() {
    qmlRegisterType<Login>("Component", 1, 0, "LoginHandler");
    qmlRegisterType<Chat>("Component", 1, 0, "ChatHandler");
    qmlRegisterType<SessionArea>("Chat", 1, 0, "SessionAreaHandler");
}
