//
// Created by 52318 on 2023/6/25.
//

#ifndef EMPLOYEE_BOSS_H
#define EMPLOYEE_BOSS_H

#endif //EMPLOYEE_BOSS_H
#pragma once
#include "iostream"
#include "empoloyee.h"

using namespace std;

class Boss :public Empoloyee
{
public:
    Boss(int id, string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};