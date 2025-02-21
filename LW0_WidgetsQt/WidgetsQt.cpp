#include "WidgetsQt.h"
#include "ui_WidgetsQt.h"

WidgetsQt::WidgetsQt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WidgetsQt)
{
    ui->setupUi(this);
}

WidgetsQt::~WidgetsQt()
{
    delete ui;
}

