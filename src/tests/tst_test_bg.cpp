#include <QtTest>

#include "../main/user.hpp"
#include "../main/expenses.hpp"
#include "../main/statement.hpp"
#include "../main/department.hpp"

class test_bg : public QObject
{
    Q_OBJECT

public:
    test_bg();
    ~test_bg();

private slots:
    //Пользователи
    void setEmptySurname();
    void setEmptyName();
    void setEmptyPatronymic();
    void setEmptyDepartment();
    void setEmptyPassword();

    //Доходы
    void setEmptyNameExp();
    void setEmptyDescription();
    void setEmptyDepartmentExp();
    void setInvalidLimit();
    void setInvalidRemainder();
};

void test_bg::setEmptySurname()
{
    //Пустое поле фамилии
    QString test_surname = "";
    QString name = "Имя";
    QString patr = "Отчество";
    QString depart = "УЛК";
    QString password = "qwerty";
    User test_user;
    test_user.setData(test_surname, name, patr, depart, password);
    QVERIFY(test_user.getSurname() == test_surname);
}

void test_bg::setEmptyName()
{
    //Пустое поле имени
    QString surname = "Фамилия";
    QString test_name = "";
    QString patr = "Отчество";
    QString depart = "УЛК";
    QString password = "qwerty";
    User test_user;
    test_user.setData(surname, test_name, patr, depart, password);
    QVERIFY(test_user.getName() == test_name);
}

void test_bg::setEmptyPatronymic()
{
    //Пустое поле отчества
    QString surname = "Фамилия";
    QString name = "Имя";
    QString test_patr = "";
    QString depart = "УЛК";
    QString password = "qwerty";
    User test_user;
    test_user.setData(surname, name, test_patr, depart, password);
    QVERIFY(test_user.getPatronymic() == test_patr);
}

void test_bg::setEmptyDepartment()
{
    //Пустое поле отдела
    QString surname = "Фамилия";
    QString name = "Имя";
    QString patr = "Отчество";
    QString test_depart = "";
    QString password = "qwerty";
    User test_user;
    test_user.setData(surname, name, patr, test_depart, password);
    QVERIFY(test_user.getDepartment() == test_depart);
}

void test_bg::setEmptyPassword()
{
    //Пустое поле пароля
    QString surname = "Фамилия";
    QString name = "Имя";
    QString patr = "Отчество";
    QString depart = "УЛК";
    QString test_password = "";
    User test_user;
    test_user.setData(surname, name, patr, depart, test_password);
    QVERIFY(test_user.getSurname() == test_password);
}

//! Расходы
void test_bg::setEmptyNameExp()
{
    QString test_name = "горничная";
    QString descr = "какое-то описание";
    QString depart = "охрана";
    size_t limit = 100;
    size_t rem = 30;
    Expenses test_exp;
    test_exp.setData(test_name, descr, depart, limit, rem);
    QVERIFY(test_exp.getName() == test_name);
}

void test_bg::setEmptyDescription()
{
    QString name = "горничная";
    QString test_descr = "";
    QString depart = "охрана";
    size_t limit = 100;
    size_t rem = 30;
    Expenses test_exp;
    test_exp.setData(name, test_descr, depart, limit, rem);
    QVERIFY(test_exp.getDescription() == test_descr);
}

void test_bg::setEmptyDepartmentExp()
{
    QString name = "горничная";
    QString descr = "какое-то описание";
    QString test_depart = "";
    size_t limit = 100;
    size_t rem = 30;
    Expenses test_exp;
    test_exp.setData(name, descr, test_depart, limit, rem);
    QVERIFY(test_exp.getDepartment() == test_depart);
}

void test_bg::setInvalidLimit()
{
    QString name = "горничная";
    QString descr = "какое-то описание";
    QString depart = "охрана";
    size_t test_limit = -5;
    size_t rem = 30;
    Expenses test_exp;
    test_exp.setData(name, descr, depart, test_limit, rem);
    QVERIFY(test_exp.getLimit() != test_limit);
}

void test_bg::setInvalidRemainder()
{
    QString name = "горничная";
    QString descr = "какое-то описание";
    QString depart = "охрана";
    size_t limit = 100;
    size_t test_rem = -5;
    Expenses test_exp;
    test_exp.setData(name, descr, depart, limit, test_rem);
    QVERIFY(test_exp.getRemainder() != test_rem);
}

//! Заявления

test_bg::test_bg()
{

}

test_bg::~test_bg()
{

}

QTEST_APPLESS_MAIN(test_bg)

#include "tst_test_bg.moc"
