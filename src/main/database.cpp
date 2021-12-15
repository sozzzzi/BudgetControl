#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
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
    m_departments.clear();
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

void DataBase::save_users_csv()
{
    QString fileName = QFileDialog::getSaveFileName(0, QString("Save Users As"), QString("Users-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);
    ost << QString("Фамилия;Имя;Отчество;Отдел;Пароль\n").toUtf8();
    for (size_t i = 0; i < m_users.size(); i++)
    {
        QString line;
        if (m_users[i].getDepartment() == "Администрация")
            continue;
        line = line + m_users[i].getSurname() + ";";
        line = line + m_users[i].getName() + ";";
        line = line + m_users[i].getPatronymic() + ";";
        line = line + m_users[i].getDepartment() + ";";
        line = line + m_users[i].getPassword() + ";\n";
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void DataBase::save_expenses_csv()
{
    QString fileName = QFileDialog::getSaveFileName(0, QString("Save Expenses As"), QString("Expenses-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);
    ost << QString("Название;Описание;Отдел;Остаток;Лимит\n").toUtf8();
    for (size_t i = 0; i < m_expenses.size(); i++)
    {
        QString line;
        line = line + m_expenses[i].getName() + ";";
        line = line + m_expenses[i].getDescription() + ";";
        line = line + m_expenses[i].getDepartment() + ";";
        line = line + QString("%1").arg(m_expenses[i].getRemainder()) + ";";
        line = line + QString("%1").arg(m_expenses[i].getLimit()) + ";\n";
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void DataBase::save_statements_csv()
{
    QString fileName = QFileDialog::getSaveFileName(0, QString("Save Statements As"), QString("Expenses-%1").arg(QDate::currentDate().toString()), "*.csv");
    QSaveFile outf(fileName);
    outf.open(QIODevice::WriteOnly);
    QTextStream ost(&outf);
    ost << QString("Работник;Отдел;Расход;Дата;Цена\n").toUtf8();
    for (size_t i = 0; i < m_statements.size(); i++)
    {
        QString line;
        line = line + m_statements[i].getEmployee() + ";";
        line = line + m_statements[i].getDepartment() + ";";
        line = line + m_statements[i].getExpenses() + ";";
        line = line + m_statements[i].getDate().toString("dd MMM yyyy HH:mm:ss") + ";";
        line = line + QString("%1").arg(m_statements[i].getCost()) + ";\n";
        line = line.toUtf8();
        ost << line;
    }
    outf.commit();
}

void DataBase::load_users_csv()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Users", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    m_users.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
        {
            first_str = false;
        }
        else
        {
            User m_user;
            QStringList list;
            for (QString item : line.split(";"))
            {
                list.push_back(item);
            }
            m_user.setSurname(list[0]);
            m_user.setName(list[1]);
            m_user.setPatronymic(list[2]);
            m_user.setDepartment(list[3]);
            m_user.setPassword(list[4]);
            m_users.push_back(m_user);
        }
    }
    file.close();
}

void DataBase::load_expenses_csv()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Expenses", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    m_users.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
        {
            first_str = false;
        }
        else
        {
            Expenses m_expense;
            QStringList list;
            for (QString item : line.split(";"))
            {
                list.push_back(item);
            }
            m_expense.setName(list[0]);
            m_expense.setDescription(list[1]);
            m_expense.setDepartment(list[2]);
            m_expense.setRemainder(list[3].toULong());
            m_expense.setLimit(list[4].toULong());
            m_expenses.push_back(m_expense);
        }
    }
    file.close();
}

void DataBase::load_statements_csv()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open Statements", "", "*.csv");
    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file); bool first_str = true;
    m_users.clear();
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if (first_str)
        {
            first_str = false;
        }
        else
        {
            Statement m_statement;
            QStringList list;
            for (QString item : line.split(";"))
            {
                list.push_back(item);
            }
            m_statement.setEmployee(list[0]);
            m_statement.setDepartment(list[1]);
            m_statement.setExpenses(list[2]);
            m_statement.setDate(QDate::fromString(list[3], "dd MMM yyyy HH:mm:ss"));
            m_statement.setCost(list[4].toULong());
            m_statements.push_back(m_statement);
        }
    }
    file.close();
}

