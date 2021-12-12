#include <QFile>
#include "database.hpp"

DataBase::DataBase()
{

}

void DataBase::save()
{
    save_users();

}

std::vector<Department> *DataBase::getDepartments()
{
    if (m_departments.empty())
        load_departments();
    return &m_departments;
}

void DataBase::save_users()
{
    QFile outf("users.bin");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_departments.size(); i++)
    {
        std::vector<User> m_users = m_departments[i].getUsers();

        for (size_t j = 0; j < m_users.size(); j++)
        {
            if (m_users[j].getDepartment() != "Администрация")
                ost << m_users[j];
        }

    }
    outf.close();
}

void DataBase::save_expanses()
{
    QFile outf("expenses.bin");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_departments.size(); i++)
    {
        std::vector<Expenses> m_expanses = m_departments[i].getExpense();

        for (size_t j = 0; j < m_expanses.size(); j++)
        {
            if (m_expanses[j].getDepartment() != "Администрация"
                    && m_expanses[j].getDepartment() != "Бухгалтерия")
                ost << m_expanses[j];
        }

    }
    outf.close();
}

Department *DataBase::getDepartment(QString m_name_department)
{
    for (size_t i = 0; i < m_departments.size(); i++)
    {
        if (m_departments[i].getName() == m_name_department)
            return &m_departments[i];
    }
    return &m_departments[0];
}

void DataBase::save_statements()
{
    QFile outf("statements.bin");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_statements.size(); i++)
    {
        ost << m_statements[i];
    }
    outf.close();
}


void DataBase::load()
{
    load_users();
    load_expenses();
    //load_statements();

}

void DataBase::load_departments()
{
    for (size_t i = 0; i < m_users.size(); i++)
    {
        if (m_users[i].getDepartment() != "Администрация" && m_users[i].getDepartment() != "Бухгалтерия")
        {
            bool find = false;
            for (size_t j = 0; j < m_departments.size(); j++)
            {
                if (m_users[i].getDepartment() == m_departments[j].getName())
                {
                    m_departments[j].addUser(m_users[i]);
                    find = true;
                }
            }
            if (!find)
            {
                Department d;
                d.setName(m_users[i].getDepartment());
                d.addUser(m_users[i]);
                m_departments.push_back(d);
            }
        }
    }

    for (size_t i = 0; i < m_expenses.size(); i++)
    {
        for (size_t j = 0; j < m_departments.size(); j++)
        {
            if (m_expenses[i].getDepartment() == m_departments[j].getName())
            {
                m_departments[j].addExpense(m_expenses[i]);
                break;
            }
        }
    }
}

void DataBase::load_users()
{
    QFile inf("users.bin");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_users.clear();
    while (!ist.atEnd())
    {
        User u;
        ist >> u;
        m_users.push_back(u);
    }
}

void DataBase::load_expenses()
{
    QFile inf("expenses.bin");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_expenses.clear();
    while (!ist.atEnd())
    {
        Expenses e;
        ist >> e;
        m_expenses.push_back(e);
    }
}

std::vector<User> *DataBase::getUsers()
{
    return &m_users;
}
