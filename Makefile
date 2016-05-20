archive_targets = 1A 1B 1C 1D 1E 1F 1G 2A 2B 2C 2D 2E 2F 2G _A B C D E F G
.PHONY: run test new $(archive_targets) clean
.DEFAULT_GOAL:= run

a.out: a.cpp
	g++-5 -std=c++11 a.cpp

run: a.out
	./a.out

test: a.out
	./a.out < a.test

new:
	cp _.cpp a.cpp

$(archive_targets):
	cp a.cpp $@.cpp
	git add $@.cpp

clean:
	rm a.*
