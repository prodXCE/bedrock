# C compiler
CC = gcc

TARGET = bedrock

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# --- Flags ---
CFLAGS = -Wall -g -I$(INC_DIR)

LDFLAGS = 

# --- Build Rules ---
SOURCES = $(wildcard $(SRC_DIR)/*.c)

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

EXECUTABLE = $(BIN_DIR)/$(TARGET)

# --- Targets ---
.PHONY: all
all: $(EXECUTABLE)

# Rules to build the final executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "build complete: $(EXECUTABLE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "cleaned build artifacts."


.PHONY: run
run: all
	@$(EXECUTABLE) $(ARGS)

