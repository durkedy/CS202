myString: main.o myString.o
	g++ main.o myString.o

main.o: main.cpp
	g++ -c main.cpp

myString.o: myString.cpp
	g++ -c myString.cpp

clean:
	rm myString.o
	rm main.o