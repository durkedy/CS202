reversi: main.o reversi.o game.o
	g++ main.o reversi.o game.o

main.o: main.cpp
	g++ -c main.cpp

reversi.o: reversi.cpp
	g++ -c reversi.cpp

game.o: game.cpp
	g++ -c game.cpp

clean:
	rm reversi.o
	rm main.o
	rm game.o