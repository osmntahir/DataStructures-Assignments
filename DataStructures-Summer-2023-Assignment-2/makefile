all:derle bagla calistir
derle:
	g++  -c -I "./include" ./src/Test.cpp -o ./lib/Test.o
	g++  -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++  -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
	g++  -c -I "./include" ./src/Agac.cpp -o ./lib/Agac.o
	g++  -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++  -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	

bagla:
	g++  ./lib/Test.o ./lib/Dugum.o ./lib/Yigin.o ./lib/Agac.o ./lib/Hucre.o ./lib/Kontrol.o -o ./bin/program.exe
calistir:
	./bin/program.exe
