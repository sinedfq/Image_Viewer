// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include <QInputDialog>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDir>
#include <QPixmap>
#include <QtDebug>
#include <QSqlError>
#include <QMouseEvent>
#include <QDateTime>
#include <QString>
#include <QToolTip>
#include <QSqlTableModel>
#include <QMenu>
#include <QContextMenuEvent>
#include <QDirIterator>
#include <QStandardPaths>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

struct PhotoInfo {
    QString fileName;
    QString dateAdded;
    QString path;
};

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QList<QPair<QString, QString>> getSortedPhotos();
    ~MainWindow();


private slots:
    void on_addPhotoButton_clicked();
    void onTimerTimeout();
    void on_deletePhotoButton_clicked();
    void on_createDatabaseButton_clicked();
    void on_openDatabaseButton_clicked();
    void on_nextPhotoButton_clicked();
    void on_prevPhotoButton_clicked();
    void on_listWidgetItemClicked(QListWidgetItem *item);
    void onDeleteAlbumButtonClicked();
    void sortDatabaseByDateUP();
    void sortDatabaseByDateDown();
    void handleContextMenuAction1();
    void handleContextMenuAction2();
    void mousePressEvent(QMouseEvent *event);
    void openImageInViewer();
    void on_action_triggered();
    void on_action_2_triggered();



private:
    Ui::MainWindow *ui;

    int totalImages;
    bool fileDialogShown;
    bool eventFilter(QObject *obj, QEvent *event) override;

    QTimer *timer;
    QString currentPhotoPath;
    QList<QString> photoPaths;
    int currentPhotoIndex;
    QString getDateAddedFromDatabase(const QString &filePath);
    QStringList getExistingDatabases();

    QSqlDatabase database;
    QString databaseName;

    void setupPhotoViewer();
    void updatePhotoViewer();

    void updateDatabaseList();
    void openSelectedDatabase(QListWidgetItem *item);
    void populateDatabaseList();

    void createDatabase(const QString &dbName);
    QString getDatabaseName();

    void loadImagesFromDatabase();
    void openDatabase(const QString &filePath);
    void updateButtons();
    void displayPhoto(const QString &filePath);
    void updateDisplay();

    QMenu *contextMenu;  // Контекстное меню для элемента списка
    int currentClickedIndex;  // Индекс элемента, на котором была вызвана контекстное меню

};

#endif // MAINWINDOW_H
