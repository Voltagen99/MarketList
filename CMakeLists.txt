cmake_minimum_required(VERSION 3.20)
project(MarketList)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

add_executable(MarketList main.cpp ShoppingList.h ShoppingItem.h Subject.h Observer.h version.h ProductVisualizer.h ShoppingList.cpp ProductVisualizer.cpp)
