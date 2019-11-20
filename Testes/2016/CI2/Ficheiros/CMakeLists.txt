cmake_minimum_required(VERSION 3.14)
project(ficheiros)

set(CMAKE_CXX_STANDARD 14)

add_executable(ficheiros main.cpp AfterSalesService.cpp Article.cpp Purchase.cpp)