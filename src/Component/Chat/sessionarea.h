#ifndef SESSIONAREA_H
#define SESSIONAREA_H

#include <QObject>

#include "chatsession.h"

class SessionArea : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ChatSession *chatSession READ chatSession WRITE setChatSession NOTIFY chatSessionChanged)

public:
    explicit SessionArea(QObject *parent = nullptr);

    ChatSession *chatSession() const;
    void setChatSession(ChatSession *chatSession);

signals:
    void chatSessionChanged();

private:
    ChatSession *m_chatSession;
};

#endif // SESSIONAREA_H
