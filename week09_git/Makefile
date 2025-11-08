CC = clang
INC = -Iinclude/
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib
LIBRARY = libmyops.so.1.o

OBJS = $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o \
	   $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o

TARGET = $(BIN_DIR)/myapp

.PHONY: all clean

all : $(TARGET)

$(TARGET): $(OBJ_DIR)/myapp.o $(LIB_DIR)/$(LIBRARY)
	$(CC) -o $@ $< -L$(LIB_DIR) -lmyops

$(LIB_DIR)/$(LIBRARY): $(OBJS)
	$(CC) -dynamiclib -o $@ $^
	ln -sf $(LIBRARY) $(LIB_DIR)/libmyops.dylib

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INC) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*