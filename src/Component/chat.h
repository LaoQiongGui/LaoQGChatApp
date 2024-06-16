#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickItem>
#include <QVector>

#include "Chat/chatsession.h"

class Chat : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<ChatSession*> chatSessions READ chatSessions CONSTANT)

public:
    explicit Chat(QObject *parent = nullptr);
    ~Chat();
    QVector<ChatSession*> chatSessions() const;

public slots:
    void newChatSession();
    void deleteChatSession(int index);
    void clearChatSession();

signals:

private:
    QVector<ChatSession*> m_chatSessions;
};

#endif // CHAT_H
