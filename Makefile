sim:
	g++ src/main.cpp src/particle.cpp src/vector.cpp -o run -I include -L lib -l SDL2-2.0.0
	./run

clean:
	rm run