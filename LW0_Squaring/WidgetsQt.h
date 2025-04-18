#ifndef WIDGETSQT_H
#define WIDGETSQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetsQt; }
QT_END_NAMESPACE

class WidgetsQt : public QMainWindow
{
    Q_OBJECT

public:
    WidgetsQt(QWidget *parent = nullptr);
    ~WidgetsQt();

private:
    Ui::WidgetsQt *ui;
};
#endif // WIDGETSQT_H
