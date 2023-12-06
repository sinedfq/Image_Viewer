#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      totalImages(0),
      fileDialogShown(false)
{
    ui->setupUi(this);
    connect(ui->addPhotoButton, SIGNAL(clicked()), this, SLOT(on_addPhotoButton_clicked()));
    connect(ui->createDatabaseButton, SIGNAL(clicked()), this, SLOT(on_createDatabaseButton_clicked()));
    connect(ui->nextPhotoButton, &QPushButton::click, this, &MainWindow::on_nextPhotoButton_clicked);
    connect(ui->prevPhotoButton, SIGNAL(click()), this, SLOT(on_prevPhotoButton_clicked()));
    connect(ui->deletePhotoButton, SIGNAL(clicked()), this, SLOT(on_deletePhotoButton_clicked()));
    connect(this, &MainWindow::updateDatabaseList, this, &MainWindow::updateDatabaseList);
    connect(ui->databaseListWidget, &QListWidget::itemClicked, this, &MainWindow::openSelectedDatabase);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::on_listWidgetItemClicked);
    connect(ui->deleteAlbumButton, &QPushButton::clicked, this, &MainWindow::onDeleteAlbumButtonClicked);
    connect(ui->sortDownButton, &QPushButton::clicked, this, &MainWindow::sortDatabaseByDateUP);
    connect(ui->sortUpButton, &QPushButton::clicked, this, &MainWindow::sortDatabaseByDateDown);

    ui->imageLabel->setMouseTracking(true);
    ui->imageLabel->installEventFilter(this);

    updateDatabaseList();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    timer->start(10000);

//    QSqlQuery query("SELECT COUNT(*) FROM photos");
//    if (query.exec() && query.next()) {
//        totalImages = query.value(0).toInt();  // Получаем общее количество изображений в базе данных
//    }

//    if (totalImages > 0) {
//        updateDisplay();
//    } else {
//        // Обработка случая, когда в базе данных нет изображений
//        currentPhotoPath = "";
//    }
    ui->listWidget->installEventFilter(this);
}

void MainWindow::on_action_triggered() {
    QString xmlText = "\t\t    Фотоальбом\n"
                      " \tИнструкция по использованию:\n\n ====================================\n\n"
                      "Создать фотоальбом - при нажатии на данную кнопку\nсоздается новый пустой фотоальбом\n\n"
                      "Удалить фотоальбом - при нажатии на данную кнопку\nпроисходит удаление выбранного альбома\n\n"
                      "Открыть фотоальбом - при нажатии на данную кнопку\nможно выбрать фотоальбом (базу данных .db)\nкоторая удовлятворяет конфигурации базы SQLite\n\n"
                      "Добавить фото- при нажатии на данную кнопку\nпроисходит открытие диалогового окна\nв котором пользователь может выбрать\nлюбую фотографию"
                      "с расширением .png .jpg .bmp\n\n"
                      "Удалить фото - при нажатии удаляется фотографи, которая сейчас выведена на экран\n\n"
                      "Следующая и предыдущая фотография - кнопки для перелистывания фотографий вперед и назад\n\n\n"
                      "При нажатии правой кнопки мыши на элементь списка появляется контекстное меню\nВ котором есть 2 кнопки:\n"
                      "    1. Удать фотографию - удаляет выбранную из списка фотографию\n   2. Скопировать изображение на рабочий стол - сохраняет выбранную из списка фотографию на рабочий стол\n\n\n"
                      "\t\tВерсия приложения - 1.0";

    // Отображение окна с текстом
    QMessageBox::information(this, "Информация", xmlText);
}

void MainWindow::on_action_2_triggered() {
    QString xmlText = "\tРазработчик:\n\nГруппа - ИП-116\n\nСтудент: Хухарев Денис Григорьеивч\n\n\Почта для связи: example@example.ru\n\n"
                      "Телеграм: example \n\n\n\tНовосибирск 2023-2024";
    QMessageBox::information(this, "Информация", xmlText);
}

void MainWindow::sortDatabaseByDateUP() {
    if (!database.isOpen()) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("База данных не открыта."));
        return;
    }

    // Выбираем фотографии из базы данных, сортируя их по дате добавления в убывающем порядке
    QSqlQuery query("SELECT * FROM photos ORDER BY date_added DESC");

    // Создаем список для хранения информации о фотографиях
    QList<PhotoInfo> photoList;

    while (query.next()) {
        PhotoInfo photo;
        photo.fileName = QFileInfo(query.value("path").toString()).fileName();
        photo.dateAdded = query.value("date_added").toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        photo.path = query.value("path").toString();
        photoList.append(photo);
    }

    // Сортируем фотографии в порядке убывания даты
    std::sort(photoList.begin(), photoList.end(), [](const PhotoInfo &a, const PhotoInfo &b) {
        return a.dateAdded > b.dateAdded;
    });

    // Очищаем список фотографий перед обновлением
    ui->listWidget->clear();

    // Вставляем отсортированные фотографии обратно в QListWidget
    for (const PhotoInfo &photo : photoList) {
        // Создаем настраиваемый виджет с изображением, метками для имени файла и даты
        QWidget *widget = new QWidget(ui->listWidget);
        QHBoxLayout *layout = new QHBoxLayout(widget);

        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(photo.path).scaled(150, 150, Qt::KeepAspectRatio));

        QLabel *fileNameLabel = new QLabel(photo.fileName.left(17) + (photo.fileName.length() > 30 ? "..." : ""));
        QLabel *dateLabel = new QLabel(photo.dateAdded);

        // Добавляем изображение и метки в горизонтальный макет
        layout->addWidget(imageLabel);

        // Добавляем разделитель пространства перед fileNameLabel для выравнивания вправо
        QSpacerItem *spacerBeforeFileName = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout->addItem(spacerBeforeFileName);

        // Выравниваем fileNameLabel по правому краю
        layout->addWidget(fileNameLabel);

        // Добавляем разделитель пространства между fileNameLabel и dateLabel
        QSpacerItem *spacerBetweenLabels = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout->addItem(spacerBetweenLabels);

        layout->addWidget(dateLabel);  // Теперь dateLabel будет еще правее

        // Устанавливаем созданный виджет в качестве элемента списка
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);

        // Устанавливаем полное название файла в качестве всплывающей подсказки
        item->setToolTip(photo.fileName);
    }

    // Очищаем и обновляем photoPaths
    photoPaths.clear();
    for (const PhotoInfo &photo : photoList) {
        photoPaths.append(photo.path);
    }
}

void MainWindow::sortDatabaseByDateDown() {
    if (!database.isOpen()) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("База данных не открыта."));
        return;
    }
    // Выбираем фотографии из базы данных, сортируя их по дате добавления в возрастающем порядке
    QSqlQuery query("SELECT * FROM photos ORDER BY date_added ASC");

    // Создаем список для хранения информации о фотографиях
    QList<PhotoInfo> photoList;

    while (query.next()) {
        PhotoInfo photo;
        photo.fileName = QFileInfo(query.value("path").toString()).fileName();
        photo.dateAdded = query.value("date_added").toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        photo.path = query.value("path").toString();
        photoList.append(photo);
    }

    // Сортируем фотографии в порядке возрастания даты
    std::sort(photoList.begin(), photoList.end(), [](const PhotoInfo &a, const PhotoInfo &b) {
        return a.dateAdded < b.dateAdded;
    });

    // Очищаем список фотографий перед обновлением
    ui->listWidget->clear();

    for (PhotoInfo &photo : photoList) {
        // Создаем настраиваемый виджет с изображением, метками для имени файла и даты
        QWidget *widget = new QWidget(ui->listWidget);
        QHBoxLayout *layout = new QHBoxLayout(widget);

        QLabel *imageLabel = new QLabel();
        imageLabel->setPixmap(QPixmap(photo.path).scaled(150, 150, Qt::KeepAspectRatio));

        QLabel *fileNameLabel = new QLabel(photo.fileName.left(17) + (photo.fileName.length() > 30 ? "..." : ""));
        QLabel *dateLabel = new QLabel(photo.dateAdded);

        // Добавляем изображение и метки в горизонтальный макет
        layout->addWidget(imageLabel);

        // Добавляем разделитель пространства перед fileNameLabel для выравнивания вправо
        QSpacerItem *spacerBeforeFileName = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout->addItem(spacerBeforeFileName);

        // Выравниваем fileNameLabel по правому краю
        layout->addWidget(fileNameLabel);

        // Добавляем разделитель пространства между fileNameLabel и dateLabel
        QSpacerItem *spacerBetweenLabels = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        layout->addItem(spacerBetweenLabels);

        layout->addWidget(dateLabel);  // Теперь dateLabel будет еще правее

        // Устанавливаем созданный виджет в качестве элемента списка
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(widget->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);

        // Устанавливаем полное название файла в качестве всплывающей подсказки
        item->setToolTip(photo.fileName);
    }

    // Очищаем и обновляем photoPaths
    photoPaths.clear();
    for (auto &photo : photoList) {
        photoPaths.append(photo.path);
    }
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    // Получаем элемент, над которым находится курсор
    QListWidgetItem *currentItem = ui->listWidget->itemAt(event->pos());
    // Проверяем, что курсор действительно находится над элементом в listWidget
    if (currentItem) {
        QMenu menu(this);
        QAction *action1 = menu.addAction("Удалить");
        QAction *action2 = menu.addAction("Сохранить на рабочий стол");

        connect(action1, &QAction::triggered, this, &MainWindow::handleContextMenuAction1);
        connect(action2, &QAction::triggered, this, &MainWindow::handleContextMenuAction2);

        menu.exec(event->globalPos());
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        // Проверяем, произошло ли событие в пределах listWidget
        if (ui->listWidget->geometry().contains(event->pos())) {
            // Получаем элемент, над которым находится курсор
            QListWidgetItem *currentItem = ui->listWidget->itemAt(event->pos());

            // Проверяем, что курсор действительно находится над элементом в listWidget
            if (currentItem) {
                QMenu menu(this);
                QAction *action1 = menu.addAction("Удалить");
                QAction *action2 = menu.addAction("Сохранить на рабочий стол");

                connect(action1, &QAction::triggered, this, &MainWindow::handleContextMenuAction1);
                connect(action2, &QAction::triggered, this, &MainWindow::handleContextMenuAction2);

                menu.exec(event->globalPos());
            }
        }
    }

    // Вызываем базовую реализацию обработчика событий мыши
    QMainWindow::mousePressEvent(event);
}

void MainWindow::handleContextMenuAction1()
{
    // Получаем текущий выбранный элемент
    QListWidgetItem *currentItem = ui->listWidget->item(currentClickedIndex);

    // Проверяем, что элемент действительно существует
    if (currentItem) {
        // Вызываем функцию удаления
        on_deletePhotoButton_clicked();
        loadImagesFromDatabase();
    }
}

QStringList MainWindow::getExistingDatabases() {

    QStringList databases;

    QString debugPath = QCoreApplication::applicationDirPath();
    QDirIterator it(debugPath, QStringList() << "*.db", QDir::Files, QDirIterator::NoIteratorFlags);

    while (it.hasNext()) {
        it.next();
        databases.append(QFileInfo(it.fileName()).baseName());
    }

    return databases;
}

void MainWindow::handleContextMenuAction2()
{
    if (ui->listWidget->selectedItems().isEmpty()) {
        return;
    }

    QListWidgetItem *selectedItem = ui->listWidget->selectedItems().first();
    int selectedIndex = ui->listWidget->row(selectedItem);

    if (selectedIndex >= 0 && selectedIndex < photoPaths.size()) {
        QString selectedPhotoPath = photoPaths[selectedIndex];

        // Получаем путь к рабочему столу пользователя
        QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

        // Сохраняем фотографию на рабочий стол
        QString fileName = QFileInfo(selectedPhotoPath).fileName();
        QString destinationPath = desktopPath + "/" + fileName;

        if (QFile::copy(selectedPhotoPath, destinationPath)) {
            QMessageBox::information(this, tr("Успех"), tr("Фотография успешно сохранена на рабочий стол."));
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сохранить фотографию на рабочий стол."));
        }
    }
}


void MainWindow::updateDatabaseList()
{

    QDir projectDir(QCoreApplication::applicationDirPath());
    QStringList filters;
    filters << "*.db";
    qDebug() << "Application directory path: " << projectDir.absolutePath();
    QStringList databaseFiles = projectDir.entryList(filters);

    // Clear the existing items in the list widget
    ui->databaseListWidget->clear();

    // Add the new items to the list widget with the .db extension
    for (const QString &databaseFile : databaseFiles) {
        QFileInfo fileInfo(databaseFile);
        QString fileNameWithoutExtension = fileInfo.baseName();

        // Create a list widget item
        QListWidgetItem *item = new QListWidgetItem(fileNameWithoutExtension);

        // Set the icon for the item
         QIcon icon("C:/Users/New/Documents/build-untitled1-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/images/1.ico");
        item->setIcon(icon);

        // Add the item to the list widget
        ui->databaseListWidget->addItem(item);
    }
}

void MainWindow::openSelectedDatabase(QListWidgetItem *item)
{
    QString selectedDatabase = item->text() + ".db";

    // Закрываем текущую базу данных (если она открыта)
    if (database.isOpen()) {
        database.close();
    }

    // Получаем путь к исполняемому файлу
    QString executablePath = QCoreApplication::applicationDirPath();

    // Собираем путь к выбранной базе данных относительно исполняемого файла
    QString databasePath = executablePath + "/../Debug/" + selectedDatabase;

    // Открываем выбранную базу данных
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databasePath);

    if (!database.open()) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("Не удалось открыть выбранную базу данных: ") + database.lastError().text());
        return;
    }

    // Вызываем вашу функцию для загрузки изображений
    loadImagesFromDatabase();

    // Вызываем вашу функцию для обновления отображения
    updateDisplay();

    // Получаем индекс выбранного элемента в listWidget
    int index = ui->listWidget->row(item);

    // Убеждаемся, что индекс корректен
    if (index >= 0 && index < photoPaths.size()) {
        currentPhotoPath = photoPaths[index];
        displayPhoto(currentPhotoPath);
    }
}

void MainWindow::on_addPhotoButton_clicked()
{
    if (database.isOpen()) {
        QString filePath;
        if (!fileDialogShown) {
            filePath = QFileDialog::getOpenFileName(this, tr("Выберите изображение"), "", tr("Изображения (*.png *.jpg *.bmp)"));
            fileDialogShown = true;
        } else {
            fileDialogShown = false;
        }

        if (!filePath.isEmpty()) {
            QDir imagesDir(QCoreApplication::applicationDirPath() + "/images");
            if (!imagesDir.exists()) {
                imagesDir.mkpath(".");
            }

            QString destinationPath = imagesDir.absoluteFilePath(QFileInfo(filePath).fileName());

            // Проверяем, существует ли файл с таким именем, и если да, добавляем уникальный суффикс
            int suffix = 1;
            while (QFile::exists(destinationPath)) {
                destinationPath = imagesDir.absoluteFilePath(QFileInfo(filePath).completeBaseName() + "_" + QString::number(suffix++) + "." + QFileInfo(filePath).suffix());
            }

            if (QFile::copy(filePath, destinationPath)) {
                // Очищаем список путей
                photoPaths.clear();

                // Добавляем путь в список
                photoPaths.append(destinationPath);

                QSqlQuery query;
                query.prepare("INSERT INTO photos (path, date_added) VALUES (:path, CURRENT_TIMESTAMP)");
                query.bindValue(":path", destinationPath);

                if (!query.exec()) {
                    QMessageBox::warning(this, tr("Ошибка базы данных"), tr("Не удалось добавить фото в базу данных."));
                    // Откатываем добавление в случае ошибки
                    photoPaths.clear();
                    QFile::remove(destinationPath);
                } else {
                    // Обновляем listWidget с новыми путями
                    loadImagesFromDatabase();
                }
            } else {
                QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось скопировать изображение."));
            }
        }
    } else {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("База данных не открыта."));
    }
}

void MainWindow::on_deletePhotoButton_clicked()
{
    if (photoPaths.isEmpty() || currentPhotoIndex >= photoPaths.size()) {
        ui->imageLabel->clear();
        return;
    }

    QString currentPhotoPath = photoPaths[currentPhotoIndex];

    if (database.isOpen() && !currentPhotoPath.isEmpty()) {
        QSqlQuery query;
        query.prepare("DELETE FROM photos WHERE path = :path");
        query.bindValue(":path", currentPhotoPath);

        if (!query.exec()) {
            QMessageBox::warning(this, tr("Ошибка базы данных"), tr("Не удалось удалить запись из базы данных."));
        }
    }
}

void MainWindow::onDeleteAlbumButtonClicked()
{
    if (!database.isOpen()) {
        qDebug() << "База данных не открыта.";
        return;
    }

    // Получаем имя текущей базы данных
    QString currentDatabaseName = database.databaseName();

    // Закрываем текущую базу данных
    database.close();

    // Удаляем файл базы данных
    QFile file(currentDatabaseName);
    if (file.remove()) {
        qDebug() << "База данных успешно удалена:" << currentDatabaseName;

        // Обновляем список баз данных
        updateDatabaseList();

        // Очищаем интерфейс или выполняем другие необходимые действия после удаления
        ui->imageLabel->clear();
        ui->listWidget->clear();
        updateButtons();
    } else {
        qDebug() << "Ошибка при удалении базы данных:" << file.errorString();
    }
}

void MainWindow::on_createDatabaseButton_clicked()
{
    QString dbName = getDatabaseName();
    if (dbName.isEmpty()) {
        return;
    }

    createDatabase(dbName);
    loadImagesFromDatabase();
}

void MainWindow::createDatabase(const QString &dbName)
{
    // Получаем путь к папке Debug
    QString debugPath = QCoreApplication::applicationDirPath();
    QString dbPath = debugPath + "/" + dbName + ".db";

    if (database.isOpen()) {
        database.close();
    }

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(dbPath);

    if (!database.open()) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("Не удалось открыть базу данных: ") + database.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS photos (id INTEGER PRIMARY KEY AUTOINCREMENT, path TEXT, date_added DATETIME)")) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("Не удалось создать таблицу photos: ") + query.lastError().text());
        return;
    }

    // Обновляем список баз данных
    updateDatabaseList();
}

QString MainWindow::getDatabaseName()
{
    if (!databaseName.isEmpty()) {
        return databaseName;
    }

    bool ok;
    databaseName = QInputDialog::getText(this, tr("Введите имя базы данных"), tr("Имя базы данных:"), QLineEdit::Normal, "", &ok);
    return ok ? databaseName.trimmed() : QString();
}

void MainWindow::on_openDatabaseButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите базу данных"), "", tr("Базы данных SQLite (*.db *.sqlite *.db3)"));

    if (!filePath.isEmpty()) {
        openDatabase(filePath);
    }

}

void MainWindow::loadImagesFromDatabase()
{
    qDebug() << "Loading images from the database";

    if (!database.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    photoPaths.clear();

    QSqlQuery query(database);
    query.prepare("SELECT path, date_added FROM photos");

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Очищаем и добавляем QLabel вместо кнопок в listWidget
    ui->listWidget->clear();
    while (query.next()) {

        QString path = query.value("path").toString();
        QString dateAdded = query.value("date_added").toString();

        QPixmap pixmap(path);

        // Создаем пользовательский виджет для элемента списка
        QWidget *customWidget = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout(customWidget);
        QLabel *iconLabel = new QLabel;
        QLabel *dateLabel = new QLabel(dateAdded); // Используйте dateAdded в качестве текста

        // Устанавливаем иконку
        iconLabel->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
        layout->addWidget(iconLabel);

        // Создаем вертикальный layout для размещения названия и даты
        QVBoxLayout *verticalLayout = new QVBoxLayout;
        QLabel *nameLabel = new QLabel(QFileInfo(path).fileName()); // Вернул название фото
        if (nameLabel->text().length() > 30) {
            QString shortName = nameLabel->text().left(27) + "...";
            nameLabel->setText(shortName);
            nameLabel->setToolTip(QFileInfo(path).fileName()); // Устанавливаем полное название в качестве всплывающей подсказки
        }
        verticalLayout->addWidget(nameLabel, 0, Qt::AlignLeft); // Название смещено на 100 единиц от левого края
        verticalLayout->addWidget(dateLabel, 0, Qt::AlignRight); // Дата справа

        // Добавляем вертикальный layout в горизонтальный layout
        layout->addLayout(verticalLayout);

        // Создаем элемент списка и устанавливаем наш пользовательский виджет
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(customWidget->sizeHint()); // Устанавливаем размер
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, customWidget);

        // Используйте dateAdded в вашем коде, где требуется дата добавления
        photoPaths.append(path);
    }

    // Устанавливаем текущую миниатюру
    if (!photoPaths.isEmpty()) {
        currentPhotoIndex = 0;
        currentPhotoPath = photoPaths[0];
        ui->listWidget->setCurrentRow(currentPhotoIndex);
        displayPhoto(currentPhotoPath);
        updateButtons();
    }
}

QString MainWindow::getDateAddedFromDatabase(const QString &filePath)
{
    QSqlQuery query(database);
    query.prepare("SELECT date_added FROM photos WHERE path = :path");
    query.bindValue(":path", filePath);

    if (query.exec() && query.next()) {
        // Предполагается, что в таблице есть поле "date_added" типа TEXT или DATETIME
        QDateTime dateAdded = QDateTime::fromString(query.value(0).toString(), Qt::ISODate);

        // Форматируем дату как строку (вы можете выбрать свой формат)
        return dateAdded.toString("yyyy-MM-dd hh:mm:ss");
    } else {
        qDebug() << "Error getting date added from the database:" << query.lastError().text();
        return QString();  // Возвращаем пустую строку в случае ошибки
    }
}

void MainWindow::on_listWidgetItemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    if (index >= 0 && index < photoPaths.size()) {
        currentPhotoIndex = index;
        currentPhotoPath = photoPaths[currentPhotoIndex];
        updateDisplay();
    }
}

void MainWindow::openDatabase(const QString &filePath)
{

    if (database.isOpen()) {
        database.close();
    }

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(filePath);

    if (!database.open()) {
        QMessageBox::critical(this, tr("Ошибка базы данных"), tr("Не удалось открыть выбранную базу данных: ") + database.lastError().text());
        return;
    }

    loadImagesFromDatabase();
    updateDisplay();
}

void MainWindow::on_nextPhotoButton_clicked()
{
    if (photoPaths.isEmpty()) {
        ui->imageLabel->clear();
        return;
    }
    if (currentPhotoIndex + 1 < photoPaths.size()) {
            currentPhotoIndex++;
        qDebug() << "Next button clicked - currentPhotoIndex:" << currentPhotoIndex;
    } else {
        return;
    }

    QString currentPhotoPath = photoPaths[currentPhotoIndex];

    updateDisplay();
}

void MainWindow::on_prevPhotoButton_clicked()
{
    if (photoPaths.isEmpty()) {
        ui->imageLabel->clear();
        return;
    }

    if (currentPhotoIndex > 0) {
        currentPhotoIndex--;
        qDebug() << "Prev button clicked - currentPhotoIndex:" << currentPhotoIndex;
    } else {
        return;
    }

    QString currentPhotoPath = photoPaths[currentPhotoIndex];

    updateDisplay();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::ToolTip) {
        if (obj == ui->listWidget) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QPoint pos = mouseEvent->pos();
            QListWidgetItem *item = ui->listWidget->itemAt(pos);

            if (item && item->text().length() > 10) {
                QToolTip::showText(mouseEvent->globalPos(), item->text());
            }
        }
        return true;
    }

    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::openImageInViewer()
{
    // Получаем путь к изображению
    QString imagePath = ui->imageLabel->toolTip();

    // Проверяем, что путь не пустой
    if (!imagePath.isEmpty()) {
        qDebug() << "Открываю изображение в просмотрщике: " << imagePath;

        // Используем QProcess для запуска программы просмотра изображений Windows
        QProcess::startDetached("mspaint.exe", {imagePath});
    }
}

void MainWindow::updateDisplay()
{
    if (photoPaths.isEmpty()) {
        ui->imageLabel->clear();
        return;
    }

    if (currentPhotoIndex >= 0 && currentPhotoIndex < photoPaths.size()) {
        currentPhotoPath = photoPaths[currentPhotoIndex];
        displayPhoto(currentPhotoPath);

        // Обновляем выделение текущей миниатюры при перелистывании
        ui->listWidget->setCurrentRow(currentPhotoIndex);
    }
}

void MainWindow::displayPhoto(const QString &filePath)
{
    QPixmap image(filePath);
    QPixmap scaledPixmap = image.scaled(500, 500, Qt::KeepAspectRatio);
    ui->imageLabel->setPixmap(scaledPixmap);
}

void MainWindow::onTimerTimeout()
{
    // Автоматически перелистываем фото на следующее при истечении времени таймера
    on_nextPhotoButton_clicked();
}

void MainWindow::updateButtons()
{
    ui->nextPhotoButton->setEnabled(photoPaths.size() > 1);
    ui->prevPhotoButton->setEnabled(photoPaths.size() > 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
