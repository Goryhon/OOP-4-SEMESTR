add_library(BigIntLib ${BIG_INT_DIR}/bigInt.cpp)
add_library(CSVLib ${CSV_DIR}/csv.cpp)
add_library(DictLib ${DICT_DIR}/dict.cpp)
add_library(LoggerLib ${LOGGER_DIR}/logger.cpp)
add_library(StackLib ${STACK_DIR}/stack.cpp)

add_subdirectory(${MODULES_TESTS_DIR})



