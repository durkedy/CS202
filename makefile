fraction: main.o fraction.o
	g++ main.o fraction.o

main.o: main.cpp
	g++ -c main.cpp

fraction.o: fraction.cpp
	g++ -c fraction.cpp

clean:
	rm fraction.o
	rm main.o