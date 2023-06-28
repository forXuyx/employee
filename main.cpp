#include <iostream>
#include <string>
#include "employeeManager.h"

using namespace std;

int main() {

    EmpoloyeeManager em;

    int choice = 0;

    // 显示菜单
    while (true)
    {
        em.Show_Menu();
        cout << "请输入你的选择：" << endl;
        cin >> choice;

        switch (choice) {
            case 0: // 退出系统
                em.ExitSystem();
                break;
            case 1: // 添加职工
                em.Add_Emp();
                break;
            case 2: // 显示职工
                em.Show_Emp();
                break;
            case 3: // 删除职工
                em.Del_Emp();
                break;
            case 4: // 修改职工
                em.Mod_Emp();
                break;
            case 5: // 查找职工
                em.Find_Emp();
                break;
            case 6: // 排序职工
                em.Sort_Emp();
                break;
            case 7: // 清空文件
                break;
            default:
                system("clear"); // linux下清屏操作
                // system("cls"); windows下请用该代码并注释上述的clear代码
                break;
        }
    }

    return 0;

}
