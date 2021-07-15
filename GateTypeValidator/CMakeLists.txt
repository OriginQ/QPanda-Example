cmake_minimum_required(VERSION 3.1)
project(GateTypeValidator)
add_executable(${PROJECT_NAME} GateTypeValidator.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
