//
// Created by 52318 on 2023/6/24.
//

#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#endif //EMPLOYEE_MANAGER_H
#pragma once
#include "iostream"
#include "empoloyee.h"

using namespace std;

class Manager :public Empoloyee
{
public:

    Manager(int id, string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取职工岗位信息
    virtual string getDeptName();
};
