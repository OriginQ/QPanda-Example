cmake_minimum_required(VERSION 3.1)
project(PMeasure)
add_executable(${PROJECT_NAME} PMeasure.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
