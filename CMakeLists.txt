cmake_minimum_required(VERSION 3.1)
project(testQPanda)
set(QPANDA_INSTALL_DIR "C:/QPanda2")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${QPANDA_INSTALL_DIR}/lib/cmake")
IF (CMAKE_BUILD_TYPE MATCHES "Debug" 
        OR CMAKE_BUILD_TYPE MATCHES "None")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Debug")
ELSEIF (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "CMAKE_BUILD_TYPE is Release")
ENDIF()
set(CMAKE_CXX_STANDARD 14)
if (MSVC)
    list(APPEND EXTRA_LDFLAGS
        -D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
        -D_CRT_SECURE_NO_WARNINGS
        /bigobj)

    if (NOT USE_MSVC_RUNTIME_LIBRARY_DLL)
        foreach (flag
            CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_RELWITHDEBINFO)

            if (${flag} MATCHES "/MDd")
                string(REGEX REPLACE "/MDd" "/MT" ${flag} "${${flag}}")
            endif()

            if (${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
            
            if (${flag} MATCHES "/W3")
                string(REGEX REPLACE "/W3" "/W0" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
else ()
    add_definitions("-w -DGTEST_USE_OWN_TR1_TUPLE=1")
    set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")
    set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")
    add_compile_options(-fpermissive)
endif()

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
find_package(QPANDA REQUIRED)
include_directories(${QPANDA_INCLUDE_DIR})
add_subdirectory(GateTypeValidator)
add_subdirectory(GetMatrix)
add_subdirectory(Measure)
add_subdirectory(OriginIRToQProg)
add_subdirectory(PMeasure)
add_subdirectory(QASMToQProg)
add_subdirectory(QCircuit)
add_subdirectory(QGate)
add_subdirectory(QGateCompare)
add_subdirectory(QGateCounter)
add_subdirectory(QIf)
add_subdirectory(QProg)
add_subdirectory(QProgClockCycle)
add_subdirectory(QProgDataParse)
add_subdirectory(QProgStored)
add_subdirectory(QProgToOriginIR)
add_subdirectory(QProgToQASM)
add_subdirectory(QProgToQuil)
add_subdirectory(QWhile)


