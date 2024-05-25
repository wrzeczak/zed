build:
	g++ -o ./bin/uno main.cpp -lraylib -lgdi32 -lwinmm -lm -std=c++17

bugbuild:
	g++ -o ./bin/uno-debug main.cpp -lraylib -lgdi32 -lwinmm -lm -std=c++17 -DDEBUG

tuxbuild:
	g++ -o ./bin/uno main.cpp -lraylib -lm -std=c++17

bugtuxbugbuild:
	g++ -o ./bin/uno-debug main.cpp -lraylib -lm -std=c++17 -DDEBUG

run: build
	./bin/uno

bugrun: bugbuild
	./bin/uno-debug

tuxrun: tuxbuild
	./bin/uno

tuxbugtuxrun: bugtuxbugbuild
	./bin/uno-debug

urn:
	@printf "#include<stdio.h>\nint main(void){printf(\"get urned lol\");return 0;}" > fart.cpp
	@g++ fart.cpp -o ProMalwareSuiteWithKeyloggerAndBitcoinMiner-0.32.4-dot-exe -lgdi32 -lwinmm
	@./ProMalwareSuiteWithKeyloggerAndBitcoinMiner-0.32.4-dot-exe
	@rm fart.cpp
	@rm ProMalwareSuiteWithKeyloggerAndBitcoinMiner-0.32.4-dot-exe