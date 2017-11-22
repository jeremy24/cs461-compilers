CFLAGS= -g3 -Wall -DLEFTTORIGHT
#CFLAGS= -O -DLEFTTORIGHT
CC=gcc

csem:	sym.o scan.o sem.o semutil.o cgram.o
	gcc -Wall -g3 -o  csem sym.o scan.o sem.o semutil.o cgram.o

sym.o:	sym.c cc.h sym.h

scan.o:	scan.c cc.h scan.h y.tab.h

sem.o:	sem.c cc.h sem.h semutil.h sym.h

semutil.o: semutil.c cc.h sem.h sym.h

y.tab.h cgram.c: cgram.y
	yacc -vd cgram.y
	mv y.tab.c cgram.c

clean:
	rm -f csem y.tab.h y.output cgram.c sym.o scan.o sem.o semutil.o cgram.o
