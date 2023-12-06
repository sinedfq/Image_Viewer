// photoviewer.cpp
#include "photoviewer.h"
#include <QVariant>
#include <QtDebug>
#include <QLabel>  // Добавьте этот заголовочный файл

PhotoViewer::PhotoViewer(QWidget *parent)
    : QWidget(parent),
      scrollArea(new QScrollArea(this)),
      scrollWidget(new QWidget(this)),
      layout(new QVBoxLayout(scrollWidget)),  // Используйте QVBoxLayout вместо QHBoxLayout
      currentIndex(0)
{
    layout->setAlignment(Qt::AlignTop);  // Измените на AlignTop, чтобы избежать выравнивания по левому краю

    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);

    connect(scrollWidget, &QWidget::customContextMenuRequested, this, &PhotoViewer::handleButtonClick);
}

void PhotoViewer::setPhotoPaths(const QList<QString> &paths)
{
    qDebug() << "Set photo paths:" << paths;
    photoPaths = paths;
    currentIndex = 0;
    showPhoto(currentIndex);

    // Обновите QScrollArea после добавления фотографий
    scrollArea->update();
}

void PhotoViewer::setCurrentIndex(int index)
{
    if (index >= 0 && index < photoPaths.size()) {
        currentIndex = index;
        showPhoto(currentIndex);
    }
}

void PhotoViewer::showPhoto(int index)
{
    clearButtons();

    if (index >= 0 && index < photoPaths.size()) {
        QPixmap pixmap(photoPaths[index]);

        QLabel *label = new QLabel(this);
        label->setPixmap(pixmap);
        label->setAlignment(Qt::AlignTop);  // Выравнивание по верхнему краю
        layout->addWidget(label);

        // Выведем путь к текущей фотографии
        qDebug() << "Show photo:" << photoPaths[index];

        // Пересчитываем и устанавливаем новый размер виджета scrollWidget
        scrollWidget->adjustSize();
    }
}

void PhotoViewer::addLabel(QLabel *label)
{
    if (label) {
        labels.append(label);
        layout->addWidget(label);
        qDebug() << "Label added successfully";
    } else {
        qDebug() << "Label is null";
    }
}



void PhotoViewer::clearButtons()
{
    qDebug() << "Clearing buttons";

    if (!layout) {
        qDebug() << "Layout is null";
        return;
    }

    // Удаление QLabel вместо QPushButton
    for (auto label : labels) {
        if (label) {
            qDebug() << "Removing label";
            layout->removeWidget(label);
            label->deleteLater();
        } else {
            qDebug() << "Label is null";
        }
    }

    labels.clear();
}

void PhotoViewer::handleButtonClick()
{
    // Также обновите этот метод, так как теперь вы используете QLabel
    QLabel *label = qobject_cast<QLabel *>(sender());
    if (label) {
        int index = labels.indexOf(label);
        if (index >= 0 && index < photoPaths.size()) {
            emit photoClicked(photoPaths[index]);
        }
    }
}
