add_executable(BigIntTests ${MODULES_TESTS_DIR}/BigIntTests.cpp)
target_link_libraries(BigIntTests BigIntLib gtest gtest_main)

add_executable(CSVTests ${MODULES_TESTS_DIR}/CsvTests.cpp)
target_link_libraries(CSVTests CSVLib gtest gtest_main)
file(COPY ${MODULES_TESTS_DIR}/input.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(DictTests ${MODULES_TESTS_DIR}/DictTests.cpp)
target_link_libraries(DictTests DictLib gtest gtest_main)

add_executable(StackTests ${MODULES_TESTS_DIR}/StackTests.cpp)
target_link_libraries(StackTests StackLib gtest gtest_main)