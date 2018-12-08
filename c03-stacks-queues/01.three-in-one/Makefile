SRC_DIR=./src
OBJ_DIR=./obj
BIN_DIR=./bin
INC_DIR=../../include

CC=g++
INCLUDES=-I$(SRC_DIR) -I$(INC_DIR)
CFLAGS=-g -O2 -Wall -Wextra -Werror -Wno-unused-function \
		  -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
		  $(INCLUDES) $(OPTFLAGS)

SOURCES=$(wildcard src/**/*.cpp src/*.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)

BIN_TARGET=$(BIN_DIR)/program.exe

all: target test

target: build $(BIN_TARGET)

rebuild: clean all

test:
	./tests/tests-io.sh $(BIN_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BIN_TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $< -o $@

build:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) || true
	rm $(OBJECTS) || true
	rm $(BIN_TARGET) || true
	rm -rf tests/output || true

