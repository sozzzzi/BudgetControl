#ifndef ACCOUNTANTMAINWINDOW_HPP
#define ACCOUNTANTMAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class AccountantMainWindow;
}

class AccountantMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountantMainWindow(QWidget *parent = nullptr);
    ~AccountantMainWindow();

private:
    Ui::AccountantMainWindow *ui;
};

#endif // ACCOUNTANTMAINWINDOW_HPP
