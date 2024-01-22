all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/number.cpp -o ./lib/number.o
	g++ -c -I "./include" ./src/digit.cpp -o ./lib/digit.o	
	g++ -c -I "./include" ./src/numberNode.cpp -o ./lib/numberNode.o
	g++ -c -I "./include" ./src/numberList.cpp -o ./lib/numberList.o
	g++ -c -I "./include" ./src/FileReader.cpp -o ./lib/FileReader.o				
bagla:
	g++ ./lib/main.o ./lib/number.o ./lib/digit.o ./lib/numberNode.o ./lib/numberList.o ./lib/FileReader.o -o ./bin/program
calistir:
	./bin/program