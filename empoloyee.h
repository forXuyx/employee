//
// Created by 52318 on 2023/6/24.
//

#ifndef EMPLOYEE_EMPOLOYEE_H
#define EMPLOYEE_EMPOLOYEE_H

#endif //EMPLOYEE_EMPOLOYEE_H
#pragma once
#include "iostream"
#include "string"

using namespace std;

// 职工抽象基类
class Empoloyee
{
public:

    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual string getDeptName() = 0;

    int m_Id; // 职工编号
    string m_Name; // 职工姓名
    int m_DeptId; // 职工部门编号
};