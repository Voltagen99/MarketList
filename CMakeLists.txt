cmake_minimum_required(VERSION 3.20)
project(MarketList)

set(CMAKE_CXX_STANDARD 14)

add_executable(MarketList main.cpp ShoppingList.h ShoppingItem.h)
