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
readonly COMPILE_COMMANDS="${BUILD_DIR}/compile_commands.json"
readonly INSTALL_MANIFEST="${BUILD_DIR}/install_manifest.txt"

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
    -i      0: Do nothing.
            1: Install with Make to /usr/local.
            2: Uninstall from system.
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
readonly BLD_UNDO=3
FLAG_BUILD=0
# Make: 0 - none, 1 - install, 2 - uninstall
readonly INS_NONE=0
readonly INS_DO=1
readonly INS_UNDO=2
FLAG_INSTALL=0

while getopts "c:b:i:h" opt
do
    case ${opt} in
    c)
        FLAG_CONFIGURE=${OPTARG}
        ;;
    b)
        FLAG_BUILD=${OPTARG}
        ;;
    i)
        FLAG_INSTALL=${OPTARG}
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
    ln -sfrv ${COMPILE_COMMANDS} ..
    ;;
${CNF_REDO})
    cd ${BUILD_DIR}
    if [[ -n "${BUILD_DIR}" ]] && [[ -d ${BUILD_DIR} ]]
    then
        rm -rv ${BUILD_DIR}/*
    fi
    cmake ..
    ln -sfrv ${COMPILE_COMMANDS} ..
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
${BLD_UNDO})
    cd ${BUILD_DIR}
    make clean
    ;;
esac

case ${FLAG_INSTALL} in
${INS_DO})
    cd ${BUILD_DIR}
    sudo make install
    ;;
${INS_UNDO})
    cd ${BUILD_DIR}
    for __file in $( cat ${INSTALL_MANIFEST} | xargs )
    do
        if [[ -n "${__file}" ]]
        then
            if [[ -f ${__file} ]]
            then
                sudo rm -v ${__file}
            elif [[ -L ${__file} ]]
            then
                sudo rm -v ${__file}
            fi
        fi
    done
    ;;
esac

exit
