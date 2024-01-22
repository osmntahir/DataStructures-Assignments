all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/test.cpp -o ./lib/test.o
	g++ -c -I "./include" ./src/Control.cpp -o ./lib/Control.o
	g++ -c -I "./include" ./src/linkedList.cpp -o ./lib/linkedList.o
	g++ -c -I "./include" ./src/ManagerList.cpp -o ./lib/ManagerList.o
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/Box.cpp -o ./lib/Box.o


	
bagla:
	g++ ./lib/test.o  ./lib/Box.o ./lib/Control.o ./lib/linkedList.o ./lib/ManagerList.o ./lib/Node.o -o ./bin/program
calistir:
	./bin/program.exe