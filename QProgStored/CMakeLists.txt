cmake_minimum_required(VERSION 3.1)
project(QProgStored)
add_executable(${PROJECT_NAME} QProgStored.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
