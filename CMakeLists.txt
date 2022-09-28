##
# Jakob Janzen
# jakob.janzen80@gmail.com
# 2022-09-24
##
set(__MINIMUM_VERSION 3.15)
cmake_minimum_required(VERSION ${__MINIMUM_VERSION} FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(JJXAlloc
    VERSION
        1.0.0
    DESCRIPTION
        "Secure memory allocation in C."
    LANGUAGES
        C;CXX
)

set(PRJ_DIR_ "${PROJECT_SOURCE_DIR}")
set(PRJ_INCLUDE_DIR_ "${PRJ_DIR_}/include")
set(PRJ_SOURCE_DIR_ "${PRJ_DIR_}/src")
set(PRJ_BINARY_DIR_ "${PRJ_DIR_}/bin")

message(STATUS "[PROJECT] - ${PROJECT_NAME} ${PROJECT_VERSION}")
message(STATUS "\t${PROJECT_DESCRIPTION}")
message(STATUS "Project root directory: ${PRJ_DIR_}")
message(STATUS "Project include directory: ${PRJ_INCLUDE_DIR_}")
message(STATUS "Project source directory: ${PRJ_SOURCE_DIR_}")
message(STATUS "Project binary directory: ${PRJ_BINARY_DIR_}")

add_executable(jjxalloc_test1_c)
target_sources(jjxalloc_test1_c PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test1.c")
add_executable(jjxalloc_test2_c)
target_sources(jjxalloc_test2_c PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test2.c")
add_executable(jjxalloc_test3_c)
target_sources(jjxalloc_test3_c PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test3.c")
set_target_properties(jjxalloc_test1_c jjxalloc_test2_c jjxalloc_test3_c PROPERTIES
    LINKER_LANGUAGE C
    C_STANDARD 11
    RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
    INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIR_}"
)

add_executable(jjxalloc_test1_cxx)
target_sources(jjxalloc_test1_cxx PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test1.cxx")
add_executable(jjxalloc_test2_cxx)
target_sources(jjxalloc_test2_cxx PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test2.cxx")
add_executable(jjxalloc_test3_cxx)
target_sources(jjxalloc_test3_cxx PRIVATE "${PRJ_SOURCE_DIR_}/jjxalloc_test3.cxx")
set_target_properties(jjxalloc_test1_cxx jjxalloc_test2_cxx jjxalloc_test3_cxx PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
    INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIR_}"
)