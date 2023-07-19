# Need the libsdl2-dev Debian package

CC = gcc
SDL_CFLAGS = $(shell pkg-config --cflags sdl2)
CFLAGS = -g -std=c99 -pedantic -Wall -Werror -Wextra -Wstrict-prototypes -Wold-style-definition $(SDL_CFLAGS)
SDL_LIBS = $(shell pkg-config --libs sdl2)

PROG = game
# The C and H files
CFILES = $(wildcard *.c)
HFILES = $(wildcard *.h)
OFILES = $(patsubst %.c,%.o,$(CFILES))

.PHONY: run-valgrind clean

$(PROG): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@ $(SDL_LIBS)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -o $@

run-valgrind: $(PROG)
	@valgrind --leak-check=full --error-exitcode=1 --show-leak-kinds=all --errors-for-leak-kinds=all ./$(PROG)

clean:
	rm -rf $(PROG) $(OFILES)
