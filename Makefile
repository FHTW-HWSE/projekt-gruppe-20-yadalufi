.PHONY: compile run

compile:
	mkdir -p build && cd build && cmake .. && make

run: compile
	./build/yadalufi