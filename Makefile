all:
	g++ -std=c++11 -Wall *.cpp -o main -lGL -lSDL2

clean:
	rm main
