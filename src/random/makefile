CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=-std=c++11
LIBS=\
	-lboost_system\
	-lboost_random
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(BIN)
.phony:clean
clean:
	rm $(BIN)
