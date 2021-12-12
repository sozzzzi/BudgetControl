#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "database.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void exit();

private:
    void authorization();
    void load_users();
    void load_expenses();
    void save_users();
    void open_mainwindow();

    Ui::MainWindow *ui;
    DataBase db;

    std::vector<User> *m_users;
    std::vector<Expenses> m_expenses;
    std::vector<Department> *m_departments;
    User m_auth_user;
};
#endif // MAINWINDOW_HPP
