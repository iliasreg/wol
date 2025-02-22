# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -I./wol -I./socket
LDFLAGS := 
TARGET := wol_app

# Source files
SRC_DIR := .
WOL_SRC := wol/wol.cpp
SOCKET_SRC := socket/socket.cpp
MAIN_SRC := src/main.cpp

# Object files
BUILD_DIR := build
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/wol.o $(BUILD_DIR)/socket.o

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link objects
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile main.cpp
$(BUILD_DIR)/main.o: $(MAIN_SRC) wol/wol.hpp socket/socket.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile wol.cpp
$(BUILD_DIR)/wol.o: $(WOL_SRC) wol/wol.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile socket.cpp
$(BUILD_DIR)/socket.o: $(SOCKET_SRC) socket/socket.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean