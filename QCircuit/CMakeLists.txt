cmake_minimum_required(VERSION 3.1)
project(QCircui)
add_executable(${PROJECT_NAME} QCircuit.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
