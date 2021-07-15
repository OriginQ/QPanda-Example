cmake_minimum_required(VERSION 3.1)
project(GetMatrix)
add_executable(${PROJECT_NAME} GetMatrix.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
