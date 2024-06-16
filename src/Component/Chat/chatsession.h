#ifndef CHATSESSION_H
#define CHATSESSION_H
#include <QObject>
#include <QString>
#include <QVector>

class ChatCompletion : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> questions READ questions WRITE setQuestions NOTIFY questionsChanged)
    Q_PROPERTY(QVector<QString> answers READ answers WRITE setAnswers NOTIFY answersChanged)
    Q_PROPERTY(QVector<QString> options READ options WRITE setOptions NOTIFY optionsChanged)

public:
    explicit ChatCompletion(QObject *parent = nullptr);

    QVector<QString> questions() const;
    void setQuestions(const QVector<QString> &questions);
    QVector<QString> answers() const;
    void setAnswers(const QVector<QString> &answers);
    QVector<QString> options() const;
    void setOptions(const QVector<QString> &options);

signals:
    void questionsChanged();
    void answersChanged();
    void optionsChanged();

private:
    QVector<QString> m_questions;
    QVector<QString> m_answers;
    QVector<QString> m_options;
};

class ChatSession : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(ChatCompletion *chatCompletion READ chatCompletion CONSTANT)

public:
    explicit ChatSession(QObject *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);
    ChatCompletion *chatCompletion() const;

signals:
    void titleChanged();

private:
    QString m_title;
    ChatCompletion *m_chatCompletion;
};

#endif // CHATSESSION_H
