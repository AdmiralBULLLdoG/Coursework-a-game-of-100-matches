CC ?= gcc
export CMOCK_DIR ?= ./cmock/
export BUILD_DIR ?= ./build
export SRC_DIR ?= ./src
export TEST_DIR ?= ./test
export TEST_BUILD_DIR ?= ${BUILD_DIR}/test
TEST_MAKEFILE = ${TEST_BUILD_DIR}/MakefileTestSupport

default: all

all: main

setup: clean
	mkdir -p ${BUILD_DIR}
	ruby ${CMOCK_DIR}scripts/create_makefile.rb

clean:
	rm -rf ${BUILD_DIR}

main: setup
	${CC} -Wall -o ${BUILD_DIR}/main ${SRC_DIR}/*c

run:
	./build/main || true

test: setup

-include ${TEST_MAKEFILE}
