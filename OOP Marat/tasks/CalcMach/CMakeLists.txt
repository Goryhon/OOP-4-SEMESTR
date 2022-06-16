include_directories(.)

add_library(CalcMachineLib calcMach.cpp)
target_link_libraries(CalcMachineLib BigIntLib StackLib DictLib LoggerLib)

add_executable(CalcMachineTest calcMachTests.cpp)
target_link_libraries(CalcMachineTest CalcMachineLib BigIntLib LoggerLib gtest gtest_main)

add_executable(CalcMachine main.cpp)
target_link_libraries(CalcMachine CalcMachineLib)