All : dir build

build : calculator  
	./bin/compiler.out
dir : 
	mkdir -p bin
calculator: bin/lex.yy.c bin/y.tab.c 
	gcc bin/lex.yy.c bin/y.tab.c src/compiler.c -o bin/compiler.out
bin/lex.yy.c : bin/y.tab.c src/compiler.l
	lex -t src/compiler.l > bin/lex.yy.c
bin/y.tab.c : src/compiler.y
	yacc -o bin/y.tab.c -d src/compiler.y

clean :
	rm -rf bin

 