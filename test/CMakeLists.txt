cmake_minimum_required(VERSION 3.20)
project(MarketList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(TEST_SOURCE_FILES runAllTests.cpp ItemSuite.cpp ShoppingTest.cpp ListSuite.cpp)
add_executable(RunMarketListTests ${TEST_SOURCE_FILES})
target_link_libraries(RunMarketListTests gtest gtest_main)