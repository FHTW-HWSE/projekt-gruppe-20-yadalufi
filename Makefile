.PHONY: compile run

compile:
	mkdir -p build && cd build && cmake .. && make

run:
	./build/yadalufi

test:
	./build/yadalufi_tests