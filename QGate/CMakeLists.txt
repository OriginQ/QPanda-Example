cmake_minimum_required(VERSION 3.1)
project(QGate)
add_executable(${PROJECT_NAME} QGate.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
