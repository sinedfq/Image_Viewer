// customlistitem.cpp
#include "customlistitem.h"

CustomListItem::CustomListItem(QWidget *parent)
    : QWidget(parent),
      textLabel(new QLabel(this)),
      imageLabel(new QLabel(this))
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(textLabel);
    layout->addWidget(imageLabel);
}

void CustomListItem::setText(const QString &text)
{
    textLabel->setText(text);
}

void CustomListItem::setImage(const QPixmap &pixmap)
{
    imageLabel->setPixmap(pixmap);
}
