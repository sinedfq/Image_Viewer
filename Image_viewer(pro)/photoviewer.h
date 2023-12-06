// photoviewer.h
#ifndef PHOTOVIEWER_H
#define PHOTOVIEWER_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>  // Добавьте этот заголовочный файл

class PhotoViewer : public QWidget
{
    Q_OBJECT

public:
    PhotoViewer(QWidget *parent = nullptr);
    void addLabel(QLabel *label);
    void setPhotoPaths(const QList<QString> &paths);
    void setCurrentIndex(int index);
    void clearButtons();


signals:
    void photoClicked(const QString &path);

private slots:
    void handleButtonClick();

private:
    void showPhoto(int index);


    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QVBoxLayout *layout;
    QList<QString> photoPaths;
    int currentIndex;

    QList<QLabel *> labels;  // Добавьте это объявление
};

#endif // PHOTOVIEWER_H
