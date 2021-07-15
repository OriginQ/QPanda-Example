cmake_minimum_required(VERSION 3.1)
project(QGateCompare)
add_executable(${PROJECT_NAME} QGateCompare.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
