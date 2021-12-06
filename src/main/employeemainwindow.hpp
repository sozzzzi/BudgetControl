#ifndef EMPLOYEEMAINWINDOW_HPP
#define EMPLOYEEMAINWINDOW_HPP

#include <QDialog>

namespace Ui {
class EmployeeMainWindow;
}

class EmployeeMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeMainWindow(QWidget *parent = nullptr);
    ~EmployeeMainWindow();

private:
    Ui::EmployeeMainWindow *ui;
};

#endif // EMPLOYEEMAINWINDOW_HPP
