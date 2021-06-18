cmake_minimum_required(VERSION 3.19)
project(sqlite_orm_phone_book)

set(CMAKE_CXX_STANDARD 20)

add_executable(sqlite_orm_phone_book main.cpp include/phonebook.hpp include/phonebook.cpp)