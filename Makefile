all: compile link run

compile:
	g++ -I"C:\SFML-2.6.2\include" -c Main_menu.cpp -o Main_menu.o
	g++ -I"C:\SFML-2.6.2\include" -c Enemy_0.cpp -o Enemy_0.o
	g++ -I"C:\SFML-2.6.2\include" -c Player.cpp -o Player.o
	g++ -I"C:\SFML-2.6.2\include" -c Stats.cpp -o Stats.o
	g++ -I"C:\SFML-2.6.2\include" -c main.cpp -o main.o

link: 
	g++ -I"C:\SFML-2.6.2\include" .\main.o .\Main_menu.o .\Player.o .\Enemy_0.o .\Stats.o -o main.exe -L"C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main 

run:
	./main.exe