all: main
	./main.exe

main: main.cpp
	g++ main.cpp -o main.exe -lsfml-system -lsfml-window -lsfml-graphics

clean:
	rm -p *.o *.exe 
