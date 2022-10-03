#!/bin/bash
##
# Jakob Janzen
# jakob.janzen80@gmail.com
# 2022-10-03
##
set -o errexit
set -o nounset
set -o pipefail

PROJECT_DIR=$(dirname "$(readlink --canonicalize-existing "${0}" 2>/dev/null)")
readonly BUILD_DIR="${PROJECT_DIR}/build"
readonly INCLUDE_DIR="${PROJECT_DIR}/include"
readonly SOURCE_DIR="${PROJECT_DIR}/src"
readonly LIBRARY_DIR="${PROJECT_DIR}/lib"
readonly BINARY_DIR="${PROJECT_DIR}/bin"

function usage {
    echo \
'Usage: '$( basename "${0}" )' [OPTIONS]
    -c      0: Do nothing.
            1: Configure CMake from the build directory.
            2: Reconfigure CMake, remove first everything in the build directory.
    -b      0: Do nothing.
            1: Build with Make from the build directory.
            2: Rebuild with Make, clean first everything.
            3: Clean everything with Make.
    -h      Show this help and exit.
'
    exit
}

# CMake: 0 - none, 1 - configure, 2 - reconfigure
readonly CNF_NONE=0
readonly CNF_DO=1
readonly CNF_REDO=2
FLAG_CONFIGURE=${CNF_NONE}
# Make: 0 - none, 1 - build, 2 - rebuild, 3 - clean
readonly BLD_NONE=0
readonly BLD_DO=1
readonly BLD_REDO=2
readonly BLD_CLEAN=3
FLAG_BUILD=0

while getopts "c:b:h" opt
do
    case ${opt} in
    c)
        FLAG_CONFIGURE=${OPTARG}
        ;;
    b)
        FLAG_BUILD=${OPTARG}
        ;;
    h)
        usage
        ;;
    esac
done

if [[ ${#} -lt 1 ]]
then
    usage
fi

case ${FLAG_CONFIGURE} in
${CNF_DO})
    cd ${BUILD_DIR}
    cmake ..
    ;;
${CNF_REDO})
    cd ${BUILD_DIR}
    if [[ -n "${BUILD_DIR}" ]] && [[ -d ${BUILD_DIR} ]]
    then
        rm -rv ${BUILD_DIR}/*
    fi
    cmake ..
    ;;
esac

case ${FLAG_BUILD} in
${BLD_DO})
    cd ${BUILD_DIR}
    make
    ;;
${BLD_REDO})
    cd ${BUILD_DIR}
    make clean
    make
    ;;
${BLD_CLEAN})
    cd ${BUILD_DIR}
    make clean
    ;;
esac

exit
