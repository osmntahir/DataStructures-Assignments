all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/agac.cpp -o ./lib/agac.o
	g++ -c -I "./include" ./src/doku.cpp -o ./lib/doku.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/hucre.cpp -o ./lib/hucre.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/organ.cpp -o ./lib/organ.o
	g++ -c -I "./include" ./src/organizma.cpp -o ./lib/organizma.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/sistem.cpp -o ./lib/sistem.o
	g++ -c -I "./include" ./src/kontrol.cpp -o ./lib/kontrol.o
	
	
	
bagla:
	g++ ./lib/kontrol.o ./lib/sistem.o ./lib/Radix.o ./lib/organizma.o ./lib/organ.o ./lib/Kuyruk.o ./lib/hucre.o ./lib/Dugum.o ./lib/doku.o ./lib/agac.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program.exe