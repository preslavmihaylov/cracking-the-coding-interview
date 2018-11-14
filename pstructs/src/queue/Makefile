OBJ_DIR=./obj
BIN_DIR=./bin
INC_DIR=../../include
TESTS_DIR=./tests

CC=g++
INCLUDES ?= -I. -I$(INC_DIR)
CFLAGS ?= -g -O2 -Wall -Wextra -Werror -Wno-unused-function \
          -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
          $(INCLUDES) $(OPTFLAGS)
TESTS_LIBS=-lcppunit

SOURCES=queue.cpp
OBJECTS=$(addprefix $(OBJ_DIR)/, $(SOURCES:%.cpp=%.o))
SLIB_TARGET=$(BIN_DIR)/queue.ar

TESTS_SOURCES=$(shell find $(TESTS_DIR) -name '*.cpp')
TESTS_OBJECTS=$(TESTS_SOURCES:%.cpp=%.o)
TESTS_TARGET=$(TESTS_DIR)/tests.exe

all: target

target: build $(SLIB_TARGET)

rebuild: clean all

test: $(TESTS_TARGET)



$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 



$(SLIB_TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(TESTS_TARGET): $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $< -o $@ $(TESTS_LIBS)



build:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) || true
	rm -rf $(BIN_DIR) || true
	rm -rf $(TESTS_TARGET) || true
	rm -rf $(TESTS_OBJECTS) || true

