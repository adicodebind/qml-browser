#ifndef WINDOWAPI_HPP
#define WINDOWAPI_HPP

#include <QObject>
#include <QStringList>
#include <QVariant>

class History;

class WindowAPI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location MEMBER m_location NOTIFY locationChanged)
    Q_PROPERTY(QString title MEMBER m_title NOTIFY titleChanged)

public:
    explicit WindowAPI(QObject *parent = nullptr);

    void setHistory(History *history);

signals:
    void locationChanged(const QString &location);
    void titleChanged(const QString &title);

public slots:
    void back();
    void forward();

    void alert(const QString &message);
    QVariant prompt(const QString &title, const QVariant &defaultValue = "");
    bool confirm(const QString &message);

private:
    History *m_history;
    QString m_location;
    QString m_title;
};

#endif // WINDOWAPI_HPP
