CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c read_file.c sort_album.c sort_album_by.c print_album.c
OBJ = $(SRC:.c=.o)
EXEC = music

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

run: fclean all
	./$(EXEC)
