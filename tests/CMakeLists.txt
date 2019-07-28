cmake_minimum_required(VERSION 2.8)
project(unit-test)
enable_testing()

#[[
    Find the GTest package
]]#
find_package(GTest REQUIRED)

#[[
    Define environment variables 
]]#
set(SRC_DIRECTORY "../src")
set(GMOCK_LIB "${CMAKE_CURRENT_SOURCE_DIR/GTest_Helper.h}")
set(VECTOR3F_HEADERS 
    "${SRC_DIRECTORY}/Vector3f/Vector3f.h"
    "${SRC_DIRECTORY}/Matrix3f/Matrix3f.h"
    "${SRC_DIRECTORY}/Matrix3f/Matrix3f.cpp" 
    "${SRC_DIRECTORY}/Math_Helper.h"
    "${SRC_DIRECTORY}/Vector3f/Vector3f_Statics.h"
   )
set(MATRIX3F_HEADERS 
    "${SRC_DIRECTORY}/Matrix3f/Matrix3f.h" 
    "${SRC_DIRECTORY}/Matrix3f/Matrix3f_Statics.h"
   )

#[[
    Include directories to be used when searching for any
    files for this CMakeLists file and any following targets
]]#
include_directories("${SRC_DIRECTORY}/Vector3f/")
include_directories("${SRC_DIRECTORY}/Matrix3f/")
include_directories("${SRC_DIRECTORY}/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

#[[
    Create executables that bind each respective unit test
    with their corressponding source files
]]#
add_executable(vector3f-unit-test
    "${CMAKE_CURRENT_SOURCE_DIR}/unit_test_vector3f.cpp"
    "${SRC_DIRECTORY}/Vector3f/Vector3f.cpp"
    ${GMOCK_LIB}
    ${VECTOR3F_HEADERS})
add_executable(matrix-unit-test
    "${CMAKE_CURRENT_SOURCE_DIR}/unit_test_matrix3f.cpp"
    "${SRC_DIRECTORY}/Matrix3f/Matrix3f.cpp"
    ${GMOCK_LIB}
    ${MATRIX3F_HEADERS})

#[[
    Link executables with the each target
]]#
target_link_libraries( vector3f-unit-test 
                       GTest::GTest GTest::Main)
target_link_libraries( matrix-unit-test
                       GTest::GTest GTest::Main)

add_test(Vector3f-Test vector3f-unit-test)
add_test(Matrix3f-Test matrix-unit-test)
