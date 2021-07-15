cmake_minimum_required(VERSION 3.1)
project(QProg)
add_executable(${PROJECT_NAME} QProg.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
