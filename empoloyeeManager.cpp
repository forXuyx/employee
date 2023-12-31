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
        // cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 文件存在但没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 文件存在，并且记录数据
    int num = this->get_EmpNum();
    // cout << "职工人数为： "  << num << endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Empoloyee*[this->m_EmpNum];
    // 存储文件中的数据到数组
    this->init_Emp();

//    for (int i = 0; i < this->m_EmpNum; i ++ )
//    {
//        cout << "职工编号：" << this->m_EmpArray[i]->m_Id
//             << "  姓名：" << this->m_EmpArray[i]->m_Name
//             << "  部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
//    }
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
            while (this->IsExist(id) != -1)
            {
                cout << "该职工编号已存在，请重新输入：" << endl;
                cin >> id;
            }

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

        // 更新职工不为空的标志
        this->m_FileIsEmpty = false;

        // 提示添加成功
        cout << "成功添加" << addNum << "名职工" << endl;

        // 保存至文件
        this->save();
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

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

int EmpoloyeeManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        // 记录人数
        num ++ ;
    }
    ifs.close();

    return num;
}

void EmpoloyeeManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0; // 数组索引
    while (ifs >> id && ifs >> name && ifs >> dId) // 获取文件中的信息存入变量中
    {
        Empoloyee * empoloyee = NULL;

        // 根据dId创建不同的对象
        if (dId == 1)
        {
            empoloyee = new Worker(id, name, dId);
        }
        else if (dId == 2)
        {
            empoloyee = new Manager(id, name, dId);
        }
        else
        {
            empoloyee = new Boss(id, name, dId);
        }

        // 存放在数组中
        this->m_EmpArray[index] = empoloyee;
        index ++ ;
    }

    ifs.close();
}

void EmpoloyeeManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i ++ )
        {
            // 利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    // 改代码等价于windows系统下的system("pause");
    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

    system("clear");
}

int EmpoloyeeManager::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i ++ )
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;

            break;
        }
    }

    return index;
}

void EmpoloyeeManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        // 按照职工编号删除
        cout << "请输入要删除的职工编号" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i ++ )
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum -- ;

            // 文件同步
            this->save();

            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }

    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

    system("clear");
}

void EmpoloyeeManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不出在或者记录为空" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            // 查找到编号的职工

            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;

            cout << "请输入新姓名：" << endl;
            cin >> newName;

            cout << "请输入岗位" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Empoloyee * empoloyee = NULL;
            switch (dSelect)
            {
                case 1:
                    empoloyee = new Worker(newId, newName, dSelect);
                    break;
                case 2:
                    empoloyee = new Manager(newId, newName, dSelect);
                    break;
                case 3:
                    empoloyee = new Boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            // 更改数据到数组中
            this->m_EmpArray[ret] = empoloyee;

            cout << "修改成功" << this->m_EmpArray[ret]->m_DeptId << endl;

            // 保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }

    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

    system("clear");
}

void EmpoloyeeManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入查询方式" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按职工姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功，信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < m_EmpNum; i ++ )
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功，职工编号为："
                         << m_EmpArray[i]->m_Id
                         << "号。信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }

    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

    system("clear");
}

void EmpoloyeeManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;

        cout << "按任意键继续..." << endl;
        system("read -s -n 1 key");

        system("clear");
    }
    else
    {
        cout << "请选择排序方法：" << endl;
        cout << "1.按职工编号进行升序" << endl;
        cout << "2.按职工编号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < m_EmpNum; i ++ )
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j ++ )
            {
                if (select == 1)
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else
                {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }

            if (i != minOrMax)
            {
                Empoloyee * temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }

        cout << "排序成功，排序结果为：" << endl;
        this->save();
        this->Show_Emp();
    }
}

void EmpoloyeeManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i ++ )
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }

    cout << "按任意键继续..." << endl;
    system("read -s -n 1 key");

    system("clear");
}