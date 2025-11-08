CC = clang
AR = ar
ROOT = $(abspath ..)
INC = -I$(ROOT)/include

SRC_DIR = $(ROOT)/advanced_ops/src
OBJ_DIR = $(ROOT)/advanced_ops/obj
LIB_DIR = $(ROOT)/lib
LIBRARY = $(LIB_DIR)/libmyadvanced.a

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(ROOT)/include/advanced_ops.h
	$(CC) -c $< -o $@ $(INC)

clean:
	rm $(OBJ_DIR)/*