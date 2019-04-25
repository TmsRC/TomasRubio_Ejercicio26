resultados.png: %.dat
	python graficar.py

all: euler.dat rk4.dat leapfrog.dat

%.dat: solucionar.x
	./solucionar.x
    
solucionar.x: solucionar.cpp
	c++ solucionar.cpp -o solucionar.x

clean:
	rm -rf *.x *.dat