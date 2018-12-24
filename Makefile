CC = g++
SOURCE = example.cpp
CFLAGS = -mrdrnd -Wall
OBJ = example

$(CC) : $(SOURCE)
	$(CC) $(CFLAGS) -o $(OBJ) $(SOURCE)

clean:
	rm -rf $(OBJ)

