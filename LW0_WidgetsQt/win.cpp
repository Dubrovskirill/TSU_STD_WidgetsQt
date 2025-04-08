#include "win.h"
Win::Win(QWidget *parent):QWidget(parent)
{

    setWindowTitle(codec->toUnicode("Возведение в квадрат"));

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel(codec->toUnicode("Введите число:"), this);
    inputEdit = new QLineEdit("", this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputLabel = new QLabel(codec->toUnicode("Результат:"), this);
    outputEdit = new QLineEdit("", this);

    nextButton = new QPushButton(codec->toUnicode("Следующее"), this);
    exitButton = new QPushButton(codec->toUnicode("Выход"), this);

    // Компоновка интерфейса
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    // Подключение сигналов и слотов
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit, SIGNAL(returnPressed()), this, SLOT(calc()));
}

void Win::begin()
{
    inputEdit->clear(); // Очищаем поле ввода
    nextButton->setEnabled(false); // Отключаем кнопку "Следующее"
    nextButton->setDefault(false);
    inputEdit->setEnabled(true); // Активируем поле ввода
    outputLabel->setVisible(false); // Скрываем метку и поле вывода
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus(); // Устанавливаем фокус на поле ввода
}

void Win::calc()
{
    bool Ok = true;
    float r, a;
    QString str = inputEdit->text();
    a = str.toDouble(&Ok); // Преобразуем строку в число

    if (Ok) // Если преобразование успешно
    {
        r = a * a; // Вычисляем квадрат
        str.setNum(r); // Преобразуем результат обратно в строку
        outputEdit->setText(str); // Отображаем результат

        inputEdit->setEnabled(false); // Блокируем поле ввода
        outputLabel->setVisible(true); // Показываем метку и поле вывода
        outputEdit->setVisible(true);
        nextButton->setDefault(true); // Устанавливаем кнопку "Следующее" как по умолчанию
        nextButton->setEnabled(true); // Активируем кнопку "Следующее"
        nextButton->setFocus(); // Устанавливаем фокус на кнопку "Следующее"
    }
    else // Если преобразование неудачно
    {
        if (!str.isEmpty()) // Если введена непустая строка
        {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec(); // Показываем сообщение об ошибке
        }
    }
}
