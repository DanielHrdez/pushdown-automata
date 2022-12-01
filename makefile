APP_NAME = pda
TEST_EXT = test
DEBUG_EXT = debug
BUILD_DIR = bin
APP = $(BUILD_DIR)/$(APP_NAME).exe
APP_TEST = $(BUILD_DIR)/$(APP_NAME).$(TEST_EXT).exe
APP_DEBUG = $(BUILD_DIR)/$(APP_NAME).$(DEBUG_EXT).exe

INCLUDE_DIR = include
INCLUDE_FILES = $(shell find $(INCLUDE_DIR)/*.h -type f)

SOURCE_DIR = src
SOURCE_FILES = $(shell find $(SOURCE_DIR)/*.cc -type f)

TEST_DIR = test
TEST_FILES = $(shell find $(TEST_DIR)/*.cc $(SOURCE_DIR)/*.cc -type f ! -path "src/main.cc")

WARNINGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

DOC_DIRS = html latex

all: compile run

mkdir_bin:
	@mkdir -p $(BUILD_DIR)

compile: lint mkdir_bin
	@g++ $(SOURCE_FILES) -o $(APP) -O3 $(WARNINGS)

run:
	@./$(APP)

debug: lint mkdir_bin
	@g++ -g $(SOURCE_FILES) -o $(APP_DEBUG) $(WARNINGS)

clean:
	@rm -rf $(BUILD_DIR) $(DOC_DIRS)

.PHONY: test
test: lint_test mkdir_bin
	@g++ $(TEST_FILES) -o $(APP_TEST) -O3 $(WARNINGS) -lgtest -lpthread
	@./$(APP_TEST)

.PHONY: doc
doc:
	@doxygen

serve: doc
	@python3 -m http.server

lint:
	@cpplint $(INCLUDE_DIR)/* $(SOURCE_DIR)/*

lint_test:
	@cpplint $(TEST_DIR)/*

commit: compile test
	@git pull && git add . && git commit -m "$(MSG)" && git push
