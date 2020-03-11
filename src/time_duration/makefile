CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=
LIBS=\
	-lboost_date_time
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(BIN)
.phony:clean
clean:
	rm $(BIN)
