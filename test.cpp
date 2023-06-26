//
// Created by 52318 on 2023/6/25.
//
#include "empoloyee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"

void test()
{
    Empoloyee * empoloyee = NULL;
    empoloyee = new Worker(1, "张三", 1);
    empoloyee->showInfo();
    delete empoloyee;

    empoloyee = new Manager(2, "李四", 2);
    empoloyee->showInfo();
    delete empoloyee;

    empoloyee = new Boss(3, "王五", 3);
    empoloyee->showInfo();
    delete empoloyee;
}
