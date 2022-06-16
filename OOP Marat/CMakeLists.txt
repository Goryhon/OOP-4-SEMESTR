cmake_minimum_required(VERSION 3.20)
project(OOP)
set(CMAKE_CXX_STANDARD 14)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

set(GOOGLE_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
set(MODULES_TESTS_DIR ${MODULES_DIR}/tests)

set(BIG_INT_DIR ${MODULES_DIR}/BigInt)
set(CSV_DIR ${MODULES_DIR}/csv)
set(DICT_DIR ${MODULES_DIR}/dict)
set(LOGGER_DIR ${MODULES_DIR}/logger)
set(STACK_DIR ${MODULES_DIR}/stack)

include_directories(${BIG_INT_DIR})
include_directories(${CSV_DIR})
include_directories(${DICT_DIR})
include_directories(${LOGGER_DIR})
include_directories(${STACK_DIR})

set(TASKS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tasks)


add_subdirectory(${GOOGLE_TEST_DIR})
add_subdirectory(${MODULES_DIR})
add_subdirectory(${TASKS_DIR})