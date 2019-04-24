rk4.png: %.dat
	python graficar.py

all: rk4_01.dat rk4_1.dat rk4_001.dat

%.dat: RungeKutta.x
	./RungeKutta.x
    
RungeKutta.x: RungeKutta.cpp
	c++ RungeKutta.cpp -o RungeKutta.x

clean:
	rm -rf *.x *.dat