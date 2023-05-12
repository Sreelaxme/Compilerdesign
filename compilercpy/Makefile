All : dir build

build : calculator  
	./bin/calc.out
dir : 
	mkdir -p bin
calculator: bin/lex.yy.c bin/y.tab.c 
	gcc bin/lex.yy.c bin/y.tab.c src/compiler.c src/toc.c src/syntaxTree.c src/param.c -o bin/calc.out
bin/lex.yy.c : bin/y.tab.c src/compiler.l
	lex -t src/compiler.l > bin/lex.yy.c
bin/y.tab.c : src/compiler.y
	yacc -o bin/y.tab.c -d src/compiler.y

clean :
	rm -rf bin
test : dir calculator
	./bin/calc.out < src/test
test2: dir calculator
	./bin/calc.out < src/prg 
test1: dir calculator
	./bin/calc.out < src/1
debug : bin/lex.yy.c bin/y.tab.c  bin/y.tab.h src/compiler.c
		gcc -g bin/lex.yy.c bin/y.tab.c src/compiler.c src/toc.c src/syntaxTree.c src/param.c -o bin/calc.out
		gdb ./bin/calc.out



output: dir calculator
	@bin/calc.out < src/test > src/output
	
%.c: %.y
%.c: %.l 