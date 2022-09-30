##
# Jakob Janzen
# jakob.janzen80@gmail.com
# 2022-09-24
##
set(__MINIMUM_VERSION 3.15)
cmake_minimum_required(VERSION ${__MINIMUM_VERSION} FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(XAlloc
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

macro(add_program TARGET_ FILE_ LANGUAGE_)
    add_executable(${TARGET_})
    target_sources(${TARGET_} PUBLIC "${PRJ_SOURCE_DIR_}/${FILE_}.${LANGUAGE_}")
    target_include_directories(${TARGET_} SYSTEM BEFORE PUBLIC "${PRJ_INCLUDE_DIR_}")
    if(${LANGUAGE_} STREQUAL c)
        set_target_properties(${TARGET_} PROPERTIES
            LINKER_LANGUAGE C
            C_STANDARD 11
            RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
            INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIR_}"
        )
    elseif(${LANGUAGE_} STREQUAL cxx)
        set_target_properties(${TARGET_} PROPERTIES
            LINKER_LANGUAGE CXX
            CXX_STANDARD 17
            RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
            INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIR_}"
        )
    endif()
endmacro()

set(GENERIC_TARGET_ xalloc_test)

add_program(${GENERIC_TARGET_}1_c ${GENERIC_TARGET_}1 c)
add_program(${GENERIC_TARGET_}2_c ${GENERIC_TARGET_}2 c)
add_program(${GENERIC_TARGET_}3_c ${GENERIC_TARGET_}3 c)

add_program(${GENERIC_TARGET_}1_cxx ${GENERIC_TARGET_}1 cxx)
add_program(${GENERIC_TARGET_}2_cxx ${GENERIC_TARGET_}2 cxx)
add_program(${GENERIC_TARGET_}3_cxx ${GENERIC_TARGET_}3 cxx)