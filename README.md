<!-- HTML generated using hilite.me --><div style="background: #ffffff; overflow:auto;width:auto;border:solid gray;border-width:.1em .1em .1em .8em;padding:.2em .6em;"><table><tr><td><pre style="margin: 0; line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49</pre></td><td><pre style="margin: 0; line-height: 125%"><span style="color: #333399; font-weight: bold">void</span> MainWindow<span style="color: #333333">::</span>on_deletePhotoButton_clicked()
{
    <span style="color: #008800; font-weight: bold">if</span> (photoPaths.isEmpty() <span style="color: #333333">||</span> currentPhotoIndex <span style="color: #333333">&gt;=</span> photoPaths.size()) {
        ui<span style="color: #333333">-&gt;</span>imageLabel<span style="color: #333333">-&gt;</span>clear();
        <span style="color: #008800; font-weight: bold">return</span>;
    }

    QString currentPhotoPath <span style="color: #333333">=</span> photoPaths[currentPhotoIndex];

    <span style="color: #008800; font-weight: bold">if</span> (database.isOpen() <span style="color: #333333">&amp;&amp;</span> <span style="color: #333333">!</span>currentPhotoPath.isEmpty()) {
        QSqlQuery query;
        query.prepare(<span style="background-color: #fff0f0">&quot;DELETE FROM photos WHERE path = :path&quot;</span>);
        query.bindValue(<span style="background-color: #fff0f0">&quot;:path&quot;</span>, currentPhotoPath);

        <span style="color: #008800; font-weight: bold">if</span> (<span style="color: #333333">!</span>query.exec()) {
            QMessageBox<span style="color: #333333">::</span>warning(<span style="color: #008800; font-weight: bold">this</span>, tr(<span style="background-color: #fff0f0">&quot;Ошибка базы данных&quot;</span>), tr(<span style="background-color: #fff0f0">&quot;Не удалось удалить запись из базы данных.&quot;</span>));
        }
    }
}

<span style="color: #333399; font-weight: bold">void</span> MainWindow<span style="color: #333333">::</span>onDeleteAlbumButtonClicked()
{
    <span style="color: #008800; font-weight: bold">if</span> (<span style="color: #333333">!</span>database.isOpen()) {
        qDebug() <span style="color: #333333">&lt;&lt;</span> <span style="background-color: #fff0f0">&quot;База данных не открыта.&quot;</span>;
        <span style="color: #008800; font-weight: bold">return</span>;
    }

    <span style="color: #888888">// Получаем имя текущей базы данных</span>
    QString currentDatabaseName <span style="color: #333333">=</span> database.databaseName();

    <span style="color: #888888">// Закрываем текущую базу данных</span>
    database.close();

    <span style="color: #888888">// Удаляем файл базы данных</span>
    QFile <span style="color: #0066BB; font-weight: bold">file</span>(currentDatabaseName);
    <span style="color: #008800; font-weight: bold">if</span> (file.remove()) {
        qDebug() <span style="color: #333333">&lt;&lt;</span> <span style="background-color: #fff0f0">&quot;База данных успешно удалена:&quot;</span> <span style="color: #333333">&lt;&lt;</span> currentDatabaseName;

        <span style="color: #888888">// Обновляем список баз данных</span>
        updateDatabaseList();

        <span style="color: #888888">// Очищаем интерфейс или выполняем другие необходимые действия после удаления</span>
        ui<span style="color: #333333">-&gt;</span>imageLabel<span style="color: #333333">-&gt;</span>clear();
        ui<span style="color: #333333">-&gt;</span>listWidget<span style="color: #333333">-&gt;</span>clear();
        updateButtons();
    } <span style="color: #008800; font-weight: bold">else</span> {
        qDebug() <span style="color: #333333">&lt;&lt;</span> <span style="background-color: #fff0f0">&quot;Ошибка при удалении базы данных:&quot;</span> <span style="color: #333333">&lt;&lt;</span> file.errorString();
    }
}
</pre></td></tr></table></div>
