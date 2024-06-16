#include "sessionarea.h"

SessionArea::SessionArea(QObject *parent)
    : QObject{parent}, m_chatSession(new ChatSession(this)) {}

ChatSession *SessionArea::chatSession() const {
    return this->m_chatSession;
}

void SessionArea::setChatSession(ChatSession *chatSession) {
    this->m_chatSession = chatSession;
}
