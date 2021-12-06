#ifndef ACCOUNTANTMAINWINDOW_HPP
#define ACCOUNTANTMAINWINDOW_HPP

#include <QDialog>

namespace Ui {
class AccountantMainWindow;
}

class AccountantMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountantMainWindow(QWidget *parent = nullptr);
    ~AccountantMainWindow();

private:
    Ui::AccountantMainWindow *ui;
};

#endif // ACCOUNTANTMAINWINDOW_HPP
