#ifndef DATABASELISTITEM_H
#define DATABASELISTITEM_H

#include <QLabel>

class DatabaseListItem : public QLabel
{
    Q_OBJECT

public:
    DatabaseListItem(const QString &text, const QPixmap &pixmap, QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // DATABASELISTITEM_H
