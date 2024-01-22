all:derle bagla calistir
derle:
	g++  -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++  -c -I "./include" ./src/satirdugum.cpp -o ./lib/satirdugum.o
	g++  -c -I "./include" ./src/satirlistesi.cpp -o ./lib/satirlistesi.o
	g++  -c -I "./include" ./src/yoneticilistesi.cpp -o ./lib/yoneticilistesi.o
bagla:
	g++  ./lib/main.o ./lib/satirdugum.o ./lib/satirlistesi.o  ./lib/yoneticilistesi.o -o ./bin/program.exe
calistir:
	./bin/program.exe
