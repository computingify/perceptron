# Makefile for the Hello World C++ program

CC = g++
CFLAGS = -Wall -Iinc -std=c++17
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# List all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Derive object file names from source file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Executable name
TARGET = perceptron

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
