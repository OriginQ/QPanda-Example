cmake_minimum_required(VERSION 3.1)
project(OriginIRToQProg)
add_executable(${PROJECT_NAME} OriginIRToQProg.cpp)
target_link_libraries(${PROJECT_NAME} ${QPANDA_LIBRARIES})
