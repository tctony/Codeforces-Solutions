run: a.out
	./a.out

test: a.out a.test
	./a.out < a.test

a.out: a.cpp
	g++-5 a.cpp

new:
	cp _.cpp a.cpp

