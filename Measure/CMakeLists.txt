cmake_minimum_required(VERSION 3.1)
project(Measure)
add_executable(${PROJECT_NAME} Measure.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
