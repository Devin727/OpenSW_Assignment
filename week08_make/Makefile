CC = clang
AR = ar
INC = -Iinclude
ROOT = $(shell pwd)

SRC_DIR = $(ROOT)/src
OBJ_DIR = $(ROOT)/obj
BIN_DIR = $(ROOT)/bin
LIB_DIR = $(ROOT)/lib

BASIC_DIR = $(ROOT)/basic_ops
ADV_DIR = $(ROOT)/advanced_ops

APP = $(BIN_DIR)/myapp
APP_OBJ = $(OBJ_DIR)/myapp.o

LIB_BASIC = $(LIB_DIR)/libmybasic.a
LIB_ADV = $(LIB_DIR)/libmyadvanced.a

.PHONY: all basic_ops advanced_ops clean

basic_ops:
	$(MAKE) -C $(BASIC_DIR)

advanced_ops:
	$(MAKE) -C $(ADV_DIR)

all : basic_ops advanced_ops $(APP)

$(APP) : $(APP_OBJ) $(LIB_BASIC) $(LIB_ADV)
	$(CC) -o $@ $^ $(INC)

$(APP_OBJ): $(SRC_DIR)/myapp.c
	$(CC) -c $< -o $@ $(INC)

clean:
	$(MAKE) -C $(BASIC_DIR) clean
	$(MAKE) -C $(ADV_DIR) clean
	rm $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/*