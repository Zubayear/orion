
# # Compiler and Flags
# CC = clang
# CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude

# # Directories
# SRC_DIR = src
# BUILD_DIR = build
# INCLUDE_DIR = include

# # Find all .c files in src/
# SRC = $(wildcard $(SRC_DIR)/*.c)
# OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# # Output executable
# TARGET = binary_tree

# # Default target
# all: $(TARGET)

# # Linking final executable
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Compile each .c file into .o
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Create build directory if it doesn't exist
# $(BUILD_DIR):
# 	mkdir -p $(BUILD_DIR)

# # Clean compiled files
# clean:
# 	rm -rf $(BUILD_DIR) $(TARGET)

# # Run the program
# run: all
# 	./$(TARGET)

# # Rebuild everything
# rebuild: clean all


# # Compiler and Flags
# CC = clang
# CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude

# # Directories
# SRC_DIR = src
# BUILD_DIR = build
# INCLUDE_DIR = include
# TEST_DIR = tests

# # Find all .c files in src/ and tests/
# SRC = $(wildcard $(SRC_DIR)/*.c)
# TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# # Object files
# OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
# TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))

# # Output executables
# TARGET = binary_tree
# TEST_TARGET = test_binary_tree

# # Default target (Builds main program and tests)
# all: $(TARGET) $(TEST_TARGET)

# # Linking final executable for the main program
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Linking final executable for tests
# $(TEST_TARGET): $(OBJ) $(TEST_OBJ)
# 	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ)

# # Compile each .c file into .o
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Compile test files separately
# $(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Create build directory if it doesn't exist
# $(BUILD_DIR):
# 	mkdir -p $(BUILD_DIR)

# # Clean compiled files
# clean:
# 	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# # Run the main program
# run: all
# 	./$(TARGET)

# # Run the test suite
# test: $(TEST_TARGET)
# 	./$(TEST_TARGET)

# # Rebuild everything
# rebuild: clean all


# Compiler and Flags
# CC = clang
# CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude

# # Directories
# SRC_DIR = src
# BUILD_DIR = build
# INCLUDE_DIR = include
# TEST_DIR = tests

# # Find all .c files in src/ and tests/
# SRC = $(wildcard $(SRC_DIR)/*.c)
# TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# # Object files
# OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
# OBJ_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o, $(OBJ))  # Exclude main.o for tests
# TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))

# # Output executables
# TARGET = binary_tree
# TEST_TARGET = test_binary_tree

# # Default target (Builds main program and tests)
# all: $(TARGET) $(TEST_TARGET)

# # Linking final executable for the main program
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Linking final executable for tests (excluding main.o)
# $(TEST_TARGET): $(OBJ_NO_MAIN) $(TEST_OBJ)
# 	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJ_NO_MAIN) $(TEST_OBJ)

# # Compile each .c file into .o
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Compile test files separately
# $(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Create build directory if it doesn't exist
# $(BUILD_DIR):
# 	mkdir -p $(BUILD_DIR)

# # Clean compiled files
# clean:
# 	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# # Run the main program
# run: all
# 	./$(TARGET)

# # Run the test suite
# test: $(TEST_TARGET)
# 	./$(TEST_TARGET)

# # Rebuild everything
# rebuild: clean all


# Compiler and Flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = tests

# Find all .c files in src/ and tests/
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
OBJ_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o, $(OBJ))  # Exclude main.o from tests
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))

# Generate test executables (one for each test source file)
TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%, $(TEST_SRC))

# Output executable for the main program
TARGET = binary_tree

# Default target (Builds main program and all tests)
all: $(TARGET) $(TEST_TARGETS)

# Linking final executable for the main program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Create individual test executables
$(BUILD_DIR)/test_%: $(BUILD_DIR)/%.o $(OBJ_NO_MAIN)
	$(CC) $(CFLAGS) -o $@ $(OBJ_NO_MAIN) $<

# Compile each .c file into .o (for src/)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files separately
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean compiled files
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGETS)

# Run the main program
run: all
	./$(TARGET)

# Run all tests
test: $(TEST_TARGETS)
	@for test_exec in $(TEST_TARGETS); do \
		echo "Running $$test_exec..."; \
		./$$test_exec; \
	done

# Rebuild everything
rebuild: clean all
