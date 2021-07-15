cmake_minimum_required(VERSION 3.1)
project(QProgToQASM)
add_executable(${PROJECT_NAME} QProgToQASM.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
