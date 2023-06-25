//
// Created by 52318 on 2023/6/25.
//
//
// Created by 52318 on 2023/6/25.
//
#include "boss.h"

Boss::Boss(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo()
{
    cout << "职工编号： " << this->m_Id;
    cout << "\t职工姓名： " << this->m_Name;
    cout << "\t岗位： " << this->getDeptName();
    cout << "\t岗位职责： 管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
    return string("总裁");
}