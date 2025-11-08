ROOT = $(abspath ..)
CC = clang
AR = ar
INC = -I$(ROOT)/include

SRC_DIR = $(ROOT)/basic_ops/src
OBJ_DIR = $(ROOT)/basic_ops/obj
LIB_DIR = $(ROOT)/lib
LIBRARY = $(LIB_DIR)/libmybasic.a

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all : $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(ROOT)/include/basic_ops.h
	$(CC) -c $< -o $@ $(INC)

clean :
	rm $(OBJ_DIR)/*