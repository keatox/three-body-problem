sim:
	g++ src/main.cpp -o run -I include -L lib -l SDL2-2.0.0
	./run
	rm run