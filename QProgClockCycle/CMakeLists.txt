cmake_minimum_required(VERSION 3.1)
project(QProgClockCycle)
add_executable(${PROJECT_NAME} QProgClockCycle.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
