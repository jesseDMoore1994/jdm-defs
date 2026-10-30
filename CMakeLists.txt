# The following CMakeLists.txt file is responsible for building and testing jdm-project.

cmake_minimum_required(VERSION 3.10)
project(jdm-project VERSION 1.0 LANGUAGES C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# set install target for the jdm-project library and header files
install(DIRECTORY include/ DESTINATION include)
