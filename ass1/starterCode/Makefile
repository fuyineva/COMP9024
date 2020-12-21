main: main.o cardRecord.o cardLL.o
	gcc -o main main.o cardRecord.o cardLL.o

main.o : main.c cardRecord.h cardLL.h
	gcc -Wall -Werror -std=c11 -c main.c

cardRecord.o : cardRecord.c cardRecord.h
	gcc -Wall -Werror -std=c11 -c cardRecord.c

cardLL.o : cardLL.c cardLL.h cardRecord.h
	gcc -Wall -Werror -std=c11 -c cardLL.c

clean:
	rm -f main main.o cardRecord.o cardLL.o core
