//
// Created by 52318 on 2023/6/24.
//

#ifndef EMPLOYEE_WORKER_H
#define EMPLOYEE_WORKER_H

#endif //EMPLOYEE_WORKER_H
#pragma once
#include "iostream"
#include "empoloyee.h"

using namespace std;

class Worker :public Empoloyee
{
public:

    // 构造函数
    Worker(int id, string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取职工岗位信息
    virtual string getDeptName();

};