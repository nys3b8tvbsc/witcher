all: witcher

witcher: *.cpp
	g++ *.cpp -std=c++17 -o witcher

clean:
	rm witcher