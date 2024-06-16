# Makefile for compiling coremp135_i2c_backlight_ctrl

# Compiler
CXX = arm-linux-gnueabihf-g++

# Source file
SRC = coremp135_i2c_backlight_ctrl.cpp

# Output executable
TARGET = coremp135_i2c_backlight_ctrl

# Compilation rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
