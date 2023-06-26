//
// Created by 52318 on 2023/6/24.
//
#include "employeeManager.h"

EmpoloyeeManager::EmpoloyeeManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
}

EmpoloyeeManager::~EmpoloyeeManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void EmpoloyeeManager::Show_Menu()
{
    cout << "------------------------" << endl;
    cout << "  欢迎使用职工管理系统  " << endl;
    cout << "    0.退出管理系统     " << endl;
    cout << "    1.增加职工信息     " << endl;
    cout << "    2.显示职工信息     " << endl;
    cout << "    3.删除职工信息     " << endl;
    cout << "    4.修改职工信息     " << endl;
    cout << "    5.查找职工信息     " << endl;
    cout << "    6.按照编号排序     " << endl;
    cout << "    7.清空所有文档     " << endl;
    cout << "------------------------" << endl;
}

void EmpoloyeeManager::ExitSystem()
{
    cout << "欢迎下次使用！" << endl;
    exit(0);
}

void EmpoloyeeManager::Add_Emp()
{
    cout << "请输入添加职工数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 添加
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Empoloyee ** newSpace = new Empoloyee*[newSize];

        // 拷贝原来空间的数据
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; ++i)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 添加新数据
        for (int i = 0; i < addNum; i ++ )
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
            cin >> name;

            cout << "请选择该职工岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Empoloyee * empoloyee = NULL;
            switch (dSelect)
            {
                case 1:
                    empoloyee = new Worker(id, name, 1);
                    break;
                case 2:
                    empoloyee = new Manager(id, name, 2);
                    break;
                case 3:
                    empoloyee = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }

            // 保存到数组中
            newSpace[this->m_EmpNum + i] = empoloyee;
        }

        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间指向
        this->m_EmpArray = newSpace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 提示添加成功
        cout << "成功添加" << addNum << "名职工" << endl;

        // 保存至文件
        this->save();
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    system("clear");
}

void EmpoloyeeManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}