# Электронный фотоальбом

Этот репозиторий содержит результаты курсовой работы студента группы ИП-116 Хухарева Д.Г. по теме "Электронный фотоальбом". Работа выполнена в рамках обучения в Сибирском государственном университете телекоммуникаций и информатики (СибГУТИ) при поддержке Министерства цифрового развития, связи и массовых коммуникаций РФ.
## Описание проекта

Проект представляет собой электронный фотоальбом, разработанный в рамках курсовой работы. 

## Автор

- Студент: Хухарев Д.Г.
- Группа: ИП-116

## СОДЕРЖАНИЕ
Введение	
1. Анализ задач и пользователей	
2. Выбор репрезентативных задач	
3. Заимствование	
4.  Протопит интерфейса	
5. Реализация	
           CWT-Анализ	
           GOMS-анализ	
Список используемых источников

## Введение

В современном мире цифровых технологий, электронные фотоальбомы становятся все более популярным средством сохранения и представления важных моментов в жизни. Отражая переход от традиционных бумажных альбомов к современным цифровым форматам, электронные фотоальбомы предоставляют пользователю удобные и гибкие инструменты для хранения, организации и обмена воспоминаниями. 
Данная курсовая работа нацелена на рассмотрение процесса создания электронного фотоальбома с использованием языка программирования C++ и среды разработки Qt Creator. Мы будем исследовать основные шаги проектирования и разработки, начиная с концептуального проектирования пользовательского интерфейса и заканчивая реализацией ключевых функций, таких как добавление фотографий и организация альбомов. Этот процесс позволит нам погрузиться в мир современных технологий программирования и раскрыть потенциал Qt Creator в создании инновационных приложений для обработки и представления фотографий.

## Анализ задач и пользователей

Для варианта задания «Электронный фотоальбом» при рассмотрении заинтересованных лиц были выбраны люди, которые имеют опыт в работе с компьютером.
Из данной категории были выбраны мама и брат.

1.	Мама: возраст - 56 лет, образование – среднее медицинское, медик, навыки работы с компьютером – средние.
2.	Брат: возраст – 36 лет, образование – высшее инженерное, программист, навыки работы с компьютером – высокие.

Пользователи программного продукта для учета спортивной школы являются лицами разного пола, имеют незаконченное или полное высшее образование. Навык владения компьютером обычно на уровне базового.
Основные термины пользователя:
•	Добавление фотографий – процесс переноса фотографий в определенный фотоальбом
•	Удаление фотографий – процесс удаления выбранной фотографии в альбоме
•	Создание нового альбома – процесс создания нового альбом и  присваивание ему названия

Возможности существующих программ по схожей тематике: 
•	Добавление фотографий
•	Удаление фотографий
•	Редактирование альбомов

## Выбор репрезентативных задач 

1.	Создание и удаление фотоальбома c указанием его имени
2.	Добавление и удаление фотографий из фотоальбома
3.	Скачивание фотографий из фотоальбома на рабочий стол
4.	Сортировка фотографий по дате добавления
5.	Предоставление помощи пользователю по интерфейсу реализованное с помощью отдельного окна вывода в виде инструкции

## Заимствование

Приложение XnViewer:
При запуске программы в левой части интерфейса  отображается дерево папок. Для открытия доступны каталоги на жёстких дисках и внешних носителях, в том числе накопители специализированной техники, вроде современных фотоаппаратов.
 
	
По клику на одной из папок в рабочей зоне появляются миниатюры фотографий с кратким описанием: имя файла, формат, развёрстка и дата. В нижней части интерфейса располагается предварительный просмотр 
 

  Фотоальбомы Вконтакте:
Внешний вид фотоальбома во ВКонтакте представляет собой набор фотоальбомов с названием и количеством фотографий в нём.
 

Так же в правом верхнем углу интерфейса можно создать новый альбом, в котором можно указать имя, описание и права доступа к альбому
 

Альбом наполнен миниатюрами фотографий, при клике на которые они открываются на полный экран. Также эти миниатюры можно сортировать по дате добавления в правой части альбома 

Также у миниатюр есть меню, в котором можно скачать, удалить фотографию или переместить её в другой альбом

## CWT-Анализ

Задача 1: Удаление фотографии
Список действий пользователя:
1.	Запустить приложение
2.	Открыть фотоальбом
3.	Выбрать фотографию
4.	Нажать на кнопку «Удалить Фотографию» (или нажать правую кнопку мыши на выбранную фотографию и нажать «Удалить»)
Анализ действий задачи 1:
С первым и третьим пунктом у пользователя не должно возникнуть затруднений.
Во втором и четвертом пунктах у пользователя может возникнуть трудность с поиском доступных фотоальбомов и удалением фотографии, для решения данной проблемы было сделано меню «Инфо», в котором находится инструкция по использованию приложения.

Задача 2: Сортировка фотографий по дате добавления
Список действий пользователя:
1.	Запустить приложение
2.	Открыть фотоальбом
3.	Отсортировать альбом
Анализ действий задачи 2:
C первым и вторым пунктом у пользователя не должно возникнуть трудностей.
В третьем пункте у пользователя могут возникнуть трудности, поскольку он может не знать в каком порядке отсортированы фотографии в альбоме. Чтобы понять в каком порядке отсортирован тот или иной альбом, пользователь может перейти в меню «Помощь» -> «Инфо», в котором указывается в каком порядке отсортированы альбомы.

## GOMS-анализ

Описание анализа 
Практически все интерфейсные взаимодействия в можно описать следующими операциями:
<div align = "center">
K – нажатие клавиши; 
B – клик кнопкой мыши; 
P – наведение указателя мыши; 
R – ожидание ответной реакции компьютера; 
H – перенос руки с клавиатуры на мышь или наоборот
D – проведение с помощью мыши прямой линии (например, выделение или прокрутка текста); 
M – мыслительная подготовка (к осуществлению одной из перечисленных операций). 
Разные пользователи выполняют указанные операции за разное время. Однако, GOMS исследует работу опытного пользователя. Многочисленные исследования выявили средние значения времени операций, выполняемых опытными пользователями. 
K 0.2 с
B 0.2 с
P 1.1 с
H 0.4 с
M 1.35 с
</div>
Цель №1: очистить весь фотоальбом, где хранится 5 фотографий
Для выполнения цели сформулируем подцели:
1.	Открыть приложение фотоальбома
2.	Выбрать альбом
3.	Нажать на любую фотографию
4.	Нажать кнопку «Удалить фотографию»
Теперь опишем методы для каждой подцели и распишем каждый метод с точностью до операции:
1.	Открытие фотоальбома c рабочего стола двойным кликом
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на значок приложения) – 1,1 с.
BB (двойной клик по иконке приложения) – 0,4 с.
2.	Выбор интересующего фотоальбома
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на альбом) – 1,1 с.
B (клик мыши на название альбома) – 0,2 с.
3.	Нажатие на любую фотографию в альбоме
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на фотографию) – 1,1 с.
B (клик мыши на фотографию) – 0,2 с.
4.	Нажимаем на кнопку «Удалить фотографию» 5 раз
М (мыслительный процесс) – 1,35 c.
P (наведение указателя мыши на кнопку) – 1,1 с.
5B (нажатие на кнопку 5 раз) – 1 с.


Общее время: M + P + BB + M + P + B + M + P + B + M + P + 5B = 11,6 с.







Цель №2: создание фотоальбома
Для выполнения цели сформулируем подцели:
1.	Открыть приложение фотоальбома
2.	Нажать на кнопку «Создать фотоальбом»
3.	Ввести название альбома (например «Альбом»)
4.	Нажать на кнопку «Ок»
Теперь опишем методы для каждой подцели и распишем каждый метод с точностью до операции:
1.	Открытие фотоальбома c рабочего стола двойным кликом
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на значок приложения) – 1,1 с.
BB (двойной клик по иконке приложения) – 0,4 с.
2.	Нажатие на кнопку «Создать фотоальбом»
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на кнопку) – 1,1 с.
B (клик мыши по кнопке) – 0,2 с.
3.	Ввод названия альбома
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на поле ввода) – 1,1 с.
B (клик мыши по полю ввода) – 0,2 с.
6K (нажатие клавиш) – 1,2 с.
4.	Нажатие на кнопку «Ок»
М (мыслительный процесс) – 1,35 с.
P (наведение указателя мыши на кнопку) – 1,1 с
B (клик мыши на кнопку) – 0,2 с.
Общее время: M + P + BB + M + P + B + M + P + B + 6K + M + P + B = 12 c.



