cmake_minimum_required(VERSION 3.1)
project(QProgToOriginIR)
add_executable(${PROJECT_NAME} QProgToOriginIR.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
