#include "databaselistitem.h"

DatabaseListItem::DatabaseListItem(const QString &text, const QPixmap &pixmap) : QListWidgetItem(QIcon(pixmap), text)
{
    this->pixmap = pixmap;
}

QPixmap DatabaseListItem::getPixmap() const
{
    return pixmap;
}
