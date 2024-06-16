#include "chatsession.h"

ChatCompletion::ChatCompletion(QObject *parent)
    : QObject{parent} {}

QVector<QString> ChatCompletion::questions() const
{
    return this->m_questions;
}

void ChatCompletion::setQuestions(const QVector<QString> &questions)
{
    this->m_questions = questions;
}

QVector<QString> ChatCompletion::answers() const
{
    return this->m_answers;
}

void ChatCompletion::setAnswers(const QVector<QString> &answers)
{
    this->m_answers = answers;
}

QVector<QString> ChatCompletion::options() const
{
    return this->m_options;
}

void ChatCompletion::setOptions(const QVector<QString> &options)
{
    this->m_options = options;
}

ChatSession::ChatSession(QObject *parent)
    : QObject{parent}, m_chatCompletion(new ChatCompletion(this)) {}

QString ChatSession::title() const
{
    return this->m_title;
}

void ChatSession::setTitle(const QString &title)
{
    this->m_title = title;
}

ChatCompletion *ChatSession::chatCompletion() const
{
    return this->m_chatCompletion;
}
