CC=gcc
FLAGS=-Wall -pedantic -std=c99
BIN=spaghetti
README=README.md

all: $(BIN)

create_readme: $(BIN)
	echo "\`\`\`"		> $(README)
	./$(BIN) --help		>> $(README)
	echo ""			>> $(README)
	./$(BIN) --print	>> $(README)
	echo "\`\`\`"		>> $(README)
	echo ""			>> $(README)
	cat README.base		>> $(README)

spaghetti: main.o spaghetti.o
	$(CC) $(FLAGS) main.o spaghetti.o -o $(BIN)

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o

spaghetti.o: spaghetti.c
	$(CC) $(FLAGS) -c spaghetti.c -o spaghetti.o

clean:
	rm -f *.o $(BIN)

install: $(BIN)
	cp $(BIN) /usr/local/bin/$(BIN)

uninstall:
	rm -f /usr/local/bin/$(BIN)
