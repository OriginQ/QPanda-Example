cmake_minimum_required(VERSION 3.1)
project(QProgDataParse)
add_executable(${PROJECT_NAME} QProgDataParse.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
