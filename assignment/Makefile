# Makefile

FILESPARS	= $(wildcard parser/src/*.c)
FILESSRC	= $(wildcard src/*.c)
CC			= g++
CFLAGS		= -g -ansi -Iinclude -Iparser/include -Iparser -lz3
OBJPARS		= $(FILESPARS:parser/src/%.c=build/%.o)
OBJSRC		= $(FILESSRC:src/%.c=build/%.o)
OBJ 		= build/Parser.o build/Lexer.o $(OBJPARS) $(OBJSRC) 

.PHONY: all
all: equalPath doc

equalPath: $(OBJ) 
		$(CC) $(CFLAGS) $(OBJ) -o equalPath

build/Lexer.o: parser/Lexer.c parser/Parser.c
		mkdir -p build
		$(CC) -c $(CFLAGS) $< -o $@

build/Parser.o: parser/Parser.c parser/Lexer.c
		mkdir -p build
		$(CC) -c $(CFLAGS) $< -o $@

parser/Lexer.c:	parser/Lexer.l 
		flex parser/Lexer.l
		mv Lexer.c parser/Lexer.c 
		mv Lexer.h parser/Lexer.h


parser/Parser.c:	parser/Parser.y parser/Lexer.c
		bison parser/Parser.y
		mv Parser.c parser/Parser.c
		mv Parser.h parser/Parser.h

build/%.o:	src/%.c 
		mkdir -p build
		$(CC) -c $(CFLAGS) $^ -o $@

build/%.o:	parser/src/%.c
		mkdir -p build
		$(CC) -c $(CFLAGS) $^ -o $@

build/graphUsage.o: examples/graphUsage.c 
		mkdir -p build
		$(CC) -c $(CFLAGS) $^ -o $@

graphParser: build/Lexer.o build/Parser.o $(OBJPARS) build/Graph.o build/graphUsage.o
		$(CC) $(CFLAGS) $^ -o $@

build/Z3Example.o: examples/Z3Example.c 
		mkdir -p build
		$(CC) -c $(CFLAGS) $^ -o $@

Z3Example: build/Z3Example.o build/Z3Tools.o
		$(CC) $(CFLAGS) $^ -o $@

.PHONY: doc
doc:
		doxygen doxygen.config
		rm -f doc.html
		ln -s doc/html/files.html doc.html

.PHONY: clean
clean:
		rm -f build/*.o *~ parser/Lexer.c parser/Lexer.h parser/Parser.c parser/Parser.h equalPath graphParser Z3Example doc.html
		rm -rf doc