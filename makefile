warehouse: main.o warehouse.o
	g++ main.o warehouse.o

main.o: main.cpp
	g++ -c main.cpp

warehouse.o: warehouse.cpp
	g++ -c warehouse.cpp

clean:
	rm warehouse.o
	rm main.o
