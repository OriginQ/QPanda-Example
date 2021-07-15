cmake_minimum_required(VERSION 3.1)
project(QWhile)
add_executable(${PROJECT_NAME} QWhile.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
