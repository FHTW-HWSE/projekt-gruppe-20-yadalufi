compile:
	if [ ! -d "./build" ]; then mkdir build; fi && rm -rf ./build/* && cd build && cmake ../CMakeLists.txt && make

run:
	if [ ! -f "./build/yadalufi" ]; then echo "./build/yadalufi does not exist. Please run 'make compile' first."; fi && ./build/yadalufi
