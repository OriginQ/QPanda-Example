cmake_minimum_required(VERSION 3.1)
project(Qif)
add_executable(${PROJECT_NAME} Qif.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
