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

debug : bin/lex.yy.c bin/y.tab.c  bin/y.tab.h src/compiler.c
		gcc -g bin/lex.yy.c bin/y.tab.c src/compiler.c src/toc.c src/syntaxTree.c src/param.c -o bin/calc.out
		gdb ./bin/calc.out



output: dir calculator
	./bin/calc.out < src/test > bin/output.c
testc: output
	gcc -o bin/op bin/output.c
	./bin/op

test_c:  dir bin/calc.out src/compiler.c src/syntaxTree.c src/param.c src/toc.c src/test
	./bin/calc.out -c temp.c < src/test
	gcc temp.c -o temp.out
	./temp.out > bin/output_c.txt
	rm temp.out temp.c
	
%.c: %.y
%.c: %.l 