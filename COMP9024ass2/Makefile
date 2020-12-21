poG: poG.o Graph.o
	gcc -o poG poG.o Graph.o -lm

poG.o : poG.c Graph.h
	gcc -Wall -Werror -std=c11 -c poG.c

Graph.o : Graph.c Graph.h
	gcc -Wall -Werror -std=c11 -c Graph.c

clean:
	rm -f poG poG.o Graph.o
