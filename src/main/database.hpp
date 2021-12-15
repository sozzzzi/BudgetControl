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
    std::vector<Statement> *getStatements();
    Department *getDepartment(QString);
    Department *getAccountant();
    void save_users();
    void save_expanses();
    void save_statements();
    void add_statement(Statement);

    void save_users_csv();
    void save_expenses_csv();
    void save_statements_csv();
    void load_users_csv();
    void load_expenses_csv();
    void load_statements_csv();

private:
    void load_users();
    void load_expenses();
    void load_statements();
    void load_departments();

    std::vector<User> m_users;
    std::vector<Expenses> m_expenses;
    std::vector<Statement> m_statements;
    std::vector<Department> m_departments;
    Department m_department_accountant;
};

#endif // DATABASE_H
