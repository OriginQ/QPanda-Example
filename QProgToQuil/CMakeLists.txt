cmake_minimum_required(VERSION 3.1)
project(QProgToQuil)
add_executable(${PROJECT_NAME} QProgToQuil.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
