# === Compiler and Flags ===
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g -Iinclude -MMD -MP

# === Directory Structure ===
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include
DEP_DIR = dep

# === File Lists ===
SOURCES  = $(wildcard $(SRC_DIR)/*.c)
OBJECTS  = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
DEPS     = $(patsubst $(SRC_DIR)/%.c, $(DEP_DIR)/%.d, $(SOURCES))
TARGET   = $(BIN_DIR)/program

# === Default Target ===
all: $(TARGET)

# === Build Final Executable ===
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

# === Compile Source Files ===
# Generates .o in obj/ and .d in dep/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	mv -f $(basename $@).d $(DEP_DIR)/$*.d

# === Create Directories if Needed ===
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(INC_DIR):
	mkdir -p $(INC_DIR)

# === Run the Program ===
run: $(TARGET)
	./$(TARGET)

# === Clean Build Artifacts ===
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(DEP_DIR)

# === Declare Phony Targets ===
.PHONY: clean run all

# === Include Auto-Generated Dependencies ===
-include $(DEPS)
