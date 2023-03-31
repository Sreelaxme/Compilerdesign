All : dir build

build : calculator  
	./bin/calc.out
dir : 
	mkdir -p bin
calculator: bin/lex.yy.c bin/y.tab.c 
	gcc bin/lex.yy.c bin/y.tab.c src/compiler.c -o bin/calc.out
bin/lex.yy.c : bin/y.tab.c src/compiler.l
	lex -t src/compiler.l > bin/lex.yy.c
bin/y.tab.c : src/compiler.y
	yacc -o bin/y.tab.c -d src/compiler.y

clean :
	rm -rf bin
test : dir calculator
	./bin/calc.out < src/1
 