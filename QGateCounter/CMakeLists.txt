cmake_minimum_required(VERSION 3.1)
project(QGateCounter)
add_executable(${PROJECT_NAME} QGateCounter.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
