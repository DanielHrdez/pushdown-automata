WARNINGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

all: compile run

mkdir_bin:
	@mkdir -p bin

compile: mkdir_bin
	@g++ src/test.cc -o bin/test.exe -O3 $(WARNINGS)

run:
	@./bin/test.exe

debug: mkdir_bin
	@g++ -g src/test.cc -o bin/test.exe $(WARNINGS)

clean:
	@rm -rf bin

test:
	