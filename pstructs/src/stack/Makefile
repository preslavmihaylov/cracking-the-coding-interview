OBJ_DIR=./obj
BIN_DIR=./bin

CC=g++
INCLUDES=-I$(SRC_DIR) -I$(INC_DIR) -I.
CFLAGS=-g -O2 -Wall -Wextra -Werror -Wno-unused-function \
		  -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
		  $(INCLUDES) $(OPTFLAGS)

SOURCES=stack.cpp
OBJECTS=$(addprefix $(OBJ_DIR)/, $(SOURCES:%.cpp=%.o))

SLIB_TARGET=$(BIN_DIR)/stack.ar

all: target

target: build $(SLIB_TARGET)

rebuild: clean all

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

$(SLIB_TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

build:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR) || true
	rm -rf $(BIN_DIR) || true

