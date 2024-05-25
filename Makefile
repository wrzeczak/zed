build:
	g++ -o ./bin/uno main.cpp -lraylib -lgdi32 -lwinmm -lm -std=c++17

bugbuild:
	g++ -o ./bin/uno-debug main.cpp -lraylib -lgdi32 -lwinmm -lm -std=c++17 -DDEBUG

run: build
	./bin/uno

bugrun: bugbuild
	./bin/uno-debug