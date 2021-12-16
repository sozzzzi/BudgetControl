#include "user.hpp"

User::User()
{

}

void User::setSurname(QString &m_surname_)
{
    m_surname = m_surname_;
}

QString &User::getSurname()
{
    return m_surname;
}
void User::setName(QString &m_name_)
{
    m_name = m_name_;
}

QString &User::getName()
{
    return m_name;
}

void User::setPatronymic(QString &m_patronymic_)
{
    m_patronymic = m_patronymic_;
}

QString &User::getPatronymic()
{
    return m_patronymic;
}

void User::setDepartment(QString &m_department_)
{
    m_department = m_department_;
}

QString &User::getDepartment()
{
    return m_department;
}

void User::setPassword(QString &m_password_)
{
    m_password = m_password_;
}

QString &User::getPassword()
{
    return m_password;
}

void User::save(QDataStream &ost) const
{
    ost << m_surname << m_name << m_patronymic << m_department << m_password;
}

bool User::setData(QString &m_surname_, QString &m_name_, QString &m_patronymic_,
                   QString &m_department_, QString &m_password_)
{
    if (m_surname_.isEmpty() || m_name_.isEmpty() || m_patronymic_.isEmpty()
            || m_department_.isEmpty() || m_password_.isEmpty())
    {
        return false;
    }

    m_surname = m_surname_;
    m_name = m_name_;
    m_patronymic = m_patronymic_;
    m_department = m_department_;
    m_password = m_password_;

    return true;
}

void User::load(QDataStream &ist)
{
    ist >> m_surname >> m_name >> m_patronymic >> m_department >> m_password;
}
