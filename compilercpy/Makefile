All : dir build

build : calculator  
	./bin/calc.out
dir : 
	mkdir -p bin
calculator: bin/lex.yy.c bin/y.tab.c 
	gcc bin/lex.yy.c bin/y.tab.c src/calc.c -o bin/calc.out
bin/lex.yy.c : bin/y.tab.c src/calc.l
	lex -t src/calc.l > bin/lex.yy.c
bin/y.tab.c : src/calc.y
	yacc -o bin/y.tab.c -d src/calc.y

clean :
	rm -rf bin
test : dir calculator
	./bin/calc.out < src/prg
 