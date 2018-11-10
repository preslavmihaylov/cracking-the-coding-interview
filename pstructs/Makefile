SRC_DIR=./src
BIN_DIR=./bin
INC_DIR=./include

CC=g++
INCLUDES=-I$(SRC_DIR) $(INC_DIR)
CFLAGS=-g -O2 -Wall -Wextra -Werror -Wno-unused-function \
		  -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
		  $(INCLUDES) $(OPTFLAGS)

STACK_PRJ=$(SRC_DIR)/stack
PROJECTS=$(STACK_PRJ) 

DLIB_TARGET=$(BIN_DIR)/pstructs.so

all: target

target: target_src
target: SLIB_TARGETS=$(shell find -name '*.ar')
target: build
	$(CC) $(SLIB_TARGETS) -fPIC -shared -o $(DLIB_TARGET)

rebuild: clean all

build:
	mkdir -p $(BIN_DIR)

clean: clean_src
	rm $(DLIB_TARGET) || true


target_src:
	$(MAKE) -C $(STACK_PRJ) target

clean_src:
	$(MAKE) -C $(STACK_PRJ) clean
