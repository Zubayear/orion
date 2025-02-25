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
# OBJ_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o, $(OBJ))  # Exclude main.o from tests
# TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))

# # Generate test executables (one for each test source file)
# TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%, $(TEST_SRC))

# # Output executable for the main program
# TARGET = main

# # Default target (Builds main program and all tests)
# all: $(TARGET) $(TEST_TARGETS)

# # Linking final executable for the main program
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Create individual test executables
# $(BUILD_DIR)/test_%: $(BUILD_DIR)/%.o $(OBJ_NO_MAIN)
# 	$(CC) $(CFLAGS) -o $@ $(OBJ_NO_MAIN) $<

# # Compile each .c file into .o (for src/)
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
# 	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGETS)

# # Run the main program
# run: all
# 	./$(TARGET)

# # Run all tests
# test: $(TEST_TARGETS)
# 	@for test_exec in $(TEST_TARGETS); do \
# 		echo "Running $$test_exec..."; \
# 		./$$test_exec; \
# 	done
# 	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGETS)

# # Rebuild everything
# rebuild: clean all



# Compiler and Flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude -MMD -MP

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

# Test executables
TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%, $(TEST_SRC))

# Output executable for the main program
TARGET = main

# Include dependency files for recompilation
DEP = $(OBJ:.o=.d) $(TEST_OBJ:.o=.d)
-include $(DEP)

# Default target (Builds main program and all tests)
all: $(TARGET) $(TEST_TARGETS)

# Linking final executable for the main program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Create individual test executables (each test links with all source files except main.o)
$(BUILD_DIR)/test_%: $(BUILD_DIR)/%.o $(OBJ_NO_MAIN)
	$(CC) $(CFLAGS) -o $@ $^   # Use $^ to include both objects correctly

# Compile each .c file into .o (for src/)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files separately
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean compiled files (but keep dependency files)
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGETS)

# Clean test binaries only (useful for rerunning tests without rebuilding everything)
clean_tests:
	rm -f $(TEST_TARGETS)

# Run the main program
run: $(TARGET)
	./$(TARGET)

# Run all tests without deleting files
test: $(TEST_TARGETS)
	@for test_exec in $(TEST_TARGETS); do \
		echo "Running $$test_exec..."; \
		./$$test_exec; \
	done

# Rebuild everything
rebuild: clean all
