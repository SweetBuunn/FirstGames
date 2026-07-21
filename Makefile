CC := gcc
CFLAGS := -g -MMD -MP

INCLUDES := -Iinclude -Isrc
LDFLAGS := -lncurses 

BUILD_DIR := build
SRC_DIR := src
TARGET := $(BUILD_DIR)/main

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run build 

all: build 

build: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(OBJS) $(INCLUDES) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	@$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)
