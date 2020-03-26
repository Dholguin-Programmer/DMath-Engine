cmake_minimum_required(VERSION 3.11)
project(DMath-Engine VERSION 1.0)
string(TOUPPER ${CMAKE_PROJECT_NAME} UPPER_PROJECT_NAME)
string(TOLOWER ${CMAKE_PROJECT_NAME} LOWER_PROJECT_NAME)
set(PROJECT_NAMESPACE MATH)

################################################################################
# Fetch toolchain from environment variable (TODO: Provide different toolchains)
set(CMAKE_C_COMPILER $ENV{TARGET_COMPILER_C})
set(CMAKE_CXX_COMPILER $ENV{TARGET_COMPILER_CXX})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AssureOutOfSourceBuild)
include(install-helpers)

################################################################################
add_subdirectory(Vector3f)
add_subdirectory(Matrix3f)
add_subdirectory(Quaternion)