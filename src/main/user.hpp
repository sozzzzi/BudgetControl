#ifndef USER_HPP
#define USER_HPP
#include <QString>

class User
{
public:
    User();
    void setSurname(QString);
    QString &getSurname();
    void setName(QString);
    QString &getName();
    void setPatronymic(QString);
    QString &getPatronymic();
    void setDepartment(QString);
    QString &getDepartment();
    void setPassword(QString);
    QString &getPassword();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString m_surname;
    QString m_name;
    QString m_patronymic;
    QString m_department;
    QString m_password;
};

inline QDataStream &operator<<(QDataStream &ost, const User &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, User &u)
{
    u.load(ist);
    return ist;
}

#endif // USER_HPP
