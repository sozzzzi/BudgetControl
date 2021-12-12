#ifndef DATABASE_H
#define DATABASE_H

#include "department.hpp"
#include "statement.hpp"

class DataBase
{
public:
    DataBase();
    void load();
    void save();
    std::vector<User> *getUsers();
    std::vector<Department> *getDepartments();
    Department *getDepartment(QString);
    void save_users();
    void save_expanses();
    void save_statements();

private:

    void load_users();
    void load_expenses();
    //void load_statements();
    void load_departments();

    std::vector<User> m_users;
    std::vector<Expenses> m_expenses;
    std::vector<Statement> m_statements;
    std::vector<Department> m_departments;
};

#endif // DATABASE_H
