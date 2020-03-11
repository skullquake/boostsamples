CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=-std=c++11
LIBS=
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(BIN)
.phony:\
	run\
	clean
run:
	$(BIN)
clean:
	rm $(BIN)
