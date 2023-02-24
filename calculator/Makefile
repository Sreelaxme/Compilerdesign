All : build

build : calculator
	./calculator.out

calculator: lex.yy.c y.tab.c 
	gcc lex.yy.c y.tab.c -o calculator.out
lex.yy.c : y.tab.c calculator.l
	lex calculator.l
y.tab.c : calculator.y
	yacc -d calculator.y

clean :
	rm -rf lex.yy.c y.tab.c calculator.out y.tab.h