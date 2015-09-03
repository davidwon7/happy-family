project(HappyFamily)
cmake_minimum_required(VERSION 2.8)

# code folderS
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(UNIT_SRC_DIR ${CMAKE_SOURCE_DIR}/unittest)
set(3RDPARTY_DIR ${CMAKE_SOURCE_DIR}/3rdparty)
set(3RDPARTY_BOOST_DIR ${3RDPARTY_DIR}/boost_1_49)
set(3RDPARTY_GTEST_DIR ${3RDPARTY_DIR}/gmock-1.7.0)

# compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} --coverage")

include_directories(${INC_DIR})
include_directories(${SRC_DIR})
include_directories(${3RDPARTY_BOOST_DIR}/include)
include_directories(${3RDPARTY_GTEST_DIR}/include)
include_directories(${UNIT_SRC_DIR})
link_directories(${3RDPARTY_GTEST_DIR}/lib)

file(GLOB SRC_LIST
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.h
    ${INC_DIR}/*.h)
add_executable(happy_family ${SRC_LIST})

file(GLOB UNIT_SRC_LIST
    ${UNIT_SRC_DIR}/*.cpp
    ${UNIT_SRC_DIR}/*.h
    ${INC_DIR}/*.h)
set(TEST_SRC_LIST
    ${UNIT_SRC_LIST}
    ${SRC_DIR}/Wife.cpp
    ${SRC_DIR}/Husband.cpp)
add_executable(unittest ${TEST_SRC_LIST})
target_link_libraries(unittest gtest gmock pthread)
