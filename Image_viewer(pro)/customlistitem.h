// customlistitem.h
#ifndef CUSTOMLISTITEM_H
#define CUSTOMLISTITEM_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class CustomListItem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomListItem(QWidget *parent = nullptr);

    void setText(const QString &text);
    void setImage(const QPixmap &pixmap);

private:
    QLabel *textLabel;
    QLabel *imageLabel;
};

#endif // CUSTOMLISTITEM_H
