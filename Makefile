# Makefile

bin/main : src/main.cpp include/functions.h include/tests.h Makefile
	g++ -I include/ -o bin/main src/main.cpp

.PHONY : clean
clean:
	rm -f bin/main
