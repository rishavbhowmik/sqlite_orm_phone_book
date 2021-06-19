cmake_minimum_required(VERSION 3.19)
project(sqlite_orm_phone_book)

set(CMAKE_CXX_STANDARD 20)

add_executable(sqlite_orm_phone_book main.cpp include/phonebook.tuple.hpp include/phonebook.tuple.cpp include/phonebook.actions.cpp include/phonebook.actions.hpp include/sqlite_orm.hpp)
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(sqlite_orm_phone_book sqlite3)