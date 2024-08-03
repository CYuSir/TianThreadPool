cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(ThreadPoolExample VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(ThreadPoolExample example.cpp)

# 包含当前目录以找到头文件
target_include_directories(ThreadPoolExample PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
