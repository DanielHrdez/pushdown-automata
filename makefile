APP_NAME = app
BUILD_DIR = bin
INCLUDE_DIR = include
SOURCE_DIR = src
TEST_DIR = test
TEST_NAME = test

WARNINGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

DOC_DIRS = html latex

all: compile run

mkdir_bin:
	@mkdir -p $(BUILD_DIR)

compile: lint mkdir_bin
	@g++ $(SOURCE_DIR)/$(APP_NAME).cc -o $(BUILD_DIR)/$(APP_NAME).exe -O3 $(WARNINGS)

run:
	@./$(BUILD_DIR)/$(APP_NAME).exe

debug: lint mkdir_bin
	@g++ -g $(SOURCE_DIR)/$(APP_NAME).cc -o $(BUILD_DIR)/$(APP_NAME).exe $(WARNINGS)

clean:
	@rm -rf $(BUILD_DIR) $(DOC_DIRS)

.PHONY: test
test: lint_test mkdir_bin
	@g++ $(TEST_DIR)/$(TEST_NAME).cc -o $(BUILD_DIR)/$(TEST_NAME).exe -O3 $(WARNINGS) -lgtest -lpthread
	@./$(BUILD_DIR)/$(TEST_NAME).exe

.PHONY: doc
doc:
	@doxygen

serve: doc
	@python3 -m http.server

lint:
	@cpplint $(INCLUDE_DIR)/* $(SOURCE_DIR)/*

lint_test:
	@cpplint $(TEST_DIR)/*

commit: test all
	@git pull && git add . && git commit -m "$(MSG)" && git push
