#include "chat.h"

Chat::Chat(QObject *parent)
    : QObject{parent} {
    this->newChatSession();
    this->newChatSession();
}

Chat::~Chat() {
    for (auto const& pChatSession : this->m_chatSessions) {
        delete pChatSession;
    }
}

QVector<ChatSession*> Chat::chatSessions() const {
    return this->m_chatSessions;
}

void Chat::newChatSession() {
    auto pChatSession = new ChatSession();
    this->m_chatSessions.push_back(pChatSession);
    pChatSession->setTitle(QString("会话") + QString::number(this->m_chatSessions.size()));
}

void Chat::deleteChatSession(int index) {
    auto pChatSession = this->m_chatSessions.at(index);
    m_chatSessions.removeAt(index);
    delete pChatSession;
}

void Chat::clearChatSession() {
    for (const auto &pChatSession : this->m_chatSessions) {
        delete pChatSession;
    }
    this->m_chatSessions.clear();
    this->newChatSession();
}


