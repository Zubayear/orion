CC = clang
CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude -MMD -MP

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
TEST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
OBJ_NO_MAIN = $(filter-out $(BUILD_DIR)/main.o, $(OBJ))  # Exclude main.o from tests
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRC))

TEST_TARGETS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/test_%, $(TEST_SRC))

TARGET = main

DEP = $(OBJ:.o=.d) $(TEST_OBJ:.o=.d)
-include $(DEP)

all: $(TARGET) $(TEST_TARGETS)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(BUILD_DIR)/test_%: $(BUILD_DIR)/%.o $(OBJ_NO_MAIN)
	$(CC) $(CFLAGS) -o $@ $^   # Use $^ to include both objects correctly

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGETS)

clean_tests:
	rm -f $(TEST_TARGETS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGETS)
	@for test_exec in $(TEST_TARGETS); do \
		echo "Running $$test_exec..."; \
		./$$test_exec; \
	done

rebuild: clean all
