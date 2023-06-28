//
// Created by 52318 on 2023/6/24.
//

#ifndef EMPLOYEE_EMPLOYEEMANAGER_H
#define EMPLOYEE_EMPLOYEEMANAGER_H

#endif //EMPLOYEE_EMPLOYEEMANAGER_H
#define FILENAME "empFile.txt"
#pragma once // 防止头文件重复包含
#include "iostream"
#include "empoloyee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"
#include "fstream"

using namespace std;

class EmpoloyeeManager
{
public:

    // 构造函数
    EmpoloyeeManager();

    // 展示菜单
    void Show_Menu();

    // 退出系统
    void ExitSystem();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Empoloyee ** m_EmpArray;

    // 标志文件是否为空
    bool m_FileIsEmpty;

    // 添加职工
    void Add_Emp();

    // 保存文件
    void save();

    // 统计人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示职工信息
    void Show_Emp();

    // 按照编号删除职工
    void Del_Emp();

    // 按照职工编号判断职工是否存在
    int IsExist(int id);

    // 修改职工
    void Mod_Emp();

    //

    // 析构函数
    ~EmpoloyeeManager();
};