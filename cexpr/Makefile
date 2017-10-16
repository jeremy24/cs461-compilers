cexpr: y.tab.c lex.yy.c
	gcc -g -o cexpr y.tab.c lex.yy.c -ll

y.tab.c: ex.y
	yacc -d ex.y

lex.yy.c: ex.l
	lex ex.l

clean:
	rm -f y.tab.c y.tab.h lex.yy.c cexpr
