CC = gcc
CFLAGS = -g -Wall -I$(INC_DIR)
LIBS = -lm
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj
BIN_DIR = ./bin
EXE_NAME = calc

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
INC_FILES := $(wildcard $(INC_DIR)/*.h)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#Helpful: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

$(info $(shell echo /src: $(SRC_FILES)))
$(info $(shell echo /include: $(INC_FILES)))

$(BIN_DIR)/$(EXE_NAME): $(OBJ_FILES)
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES)
	rm -f $(BIN_DIR)/$(EXE_NAME)