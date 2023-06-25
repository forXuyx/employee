cmake_minimum_required(VERSION 3.25)
project(employee)

set(CMAKE_CXX_STANDARD 17)

add_executable(employee main.cpp main.cpp employeeManager.h empoloyeeManager.cpp empoloyee.h worker.h worker.cpp manager.h manager.h manager.cpp manager.cpp boss.h boss.cpp test.cpp)
