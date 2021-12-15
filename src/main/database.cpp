#include <QFile>
#include "database.hpp"

DataBase::DataBase()
{
    m_department_accountant.setName("Бухгалтерия");
}

void DataBase::save()
{
    save_users();
    save_expanses();
    save_statements();
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

Department *DataBase::getAccountant()
{
    return &m_department_accountant;
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

void DataBase::load_statements()
{
    QFile inf("statements.bin");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_statements.clear();
    while (!ist.atEnd())
    {
        Statement st;
        ist >> st;
        m_statements.push_back(st);
    }
}

void DataBase::add_statement(Statement m_statement_)
{
    QFile outf("statements.bin");
    outf.open(QIODevice::Append);
    QDataStream out(&outf);
    out << m_statement_;
}

std::vector<Statement> *DataBase::getStatements()
{
    return &m_statements;
}

void DataBase::load()
{
    load_users();
    load_expenses();
    load_statements();
}

void DataBase::load_departments()
{
    for (size_t i = 0; i < m_users.size(); i++)
    {
        if (m_users[i].getDepartment() == "Бухгалтерия")
        {
            m_department_accountant.addUser(m_users[i]);
        }
        else if (m_users[i].getDepartment() != "Администрация")
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

    //для тестов +4 пользователя

//    User user1;
//    user1.setSurname("Абобов");
//    user1.setName("Абоба");
//    user1.setPatronymic("Абобович");
//    user1.setDepartment("Бухгалтерия");
//    user1.setPassword("я лучший тупа");
//    m_users.push_back(user1);

//    User user2;
//    user2.setSurname("Биба");
//    user2.setName("Бибович");
//    user2.setPatronymic("Бибов");
//    user2.setDepartment("Преподаватели");
//    user2.setPassword("я бибка ы");
//    m_users.push_back(user2);

//    User user3;
//    user3.setSurname("Лупов");
//    user3.setName("Лупа");
//    user3.setPatronymic("Лупович");
//    user3.setDepartment("Охрана");
//    user3.setPassword("за мной пупа");
//    m_users.push_back(user3);

//    User user4;
//    user4.setSurname("Пупов");
//    user4.setName("Пупа");
//    user4.setPatronymic("Пупович");
//    user4.setDepartment("Охрана");
//    user4.setPassword("я иду после лупы");
//    m_users.push_back(user4);

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
