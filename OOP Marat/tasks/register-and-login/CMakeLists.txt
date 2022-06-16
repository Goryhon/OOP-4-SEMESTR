include_directories(.)
add_library(authLib authorizer.cpp)
target_link_libraries(authLib LoggerLib CSVLib DictLib)

add_executable(login login.cpp)
target_link_libraries(login authLib)
add_executable(register register.cpp)
target_link_libraries(register authLib)

file(COPY users.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})