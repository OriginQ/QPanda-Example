cmake_minimum_required(VERSION 3.1)
project(QASMToQProg)
add_executable(${PROJECT_NAME} QASMToQProg.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
