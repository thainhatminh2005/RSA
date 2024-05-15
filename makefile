CC = gcc
FLAGS = -Ofast
SPATH = ./usr/bin
SHELL = $(SPATH)/sh.exe

BUILD_DIR = ./build
SRC_DIR = ./source
HDR_DIR = ./header

SRCS = $(shell $(SPATH)/dir $(SRC_DIR))
# SRCS = main.c cmd.c int256.c pv.c ui.c uilib.c rsa.c
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(patsubst %,$(HDR_DIR)/%,$(shell $(SPATH)/dir $(HDR_DIR)))

all: main launch

main: $(OBJS)
	$(CC) -lpthread -o $@ $^ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(SPATH)/mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

launch: $(BUILD_DIR)/launch.o
	$(CC) -o $@ $^

$(BUILD_DIR)\launch.o: launch.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

# .PHONY: clean
# clean:
# 	rm -r $(BUILD_DIR)
