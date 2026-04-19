CC=gcc
CFLAGS=-g -O2 -std=c11 -pedantic -Wall -Wextra

SRCS    = htab_hash_function.c htab_init.c htab_clear.c htab_free.c htab_size.c \
		htab_bucket_count.c htab_find.c htab_lookup_add.c htab_erase.c htab_for_each.c
OBJS    = $(SRCS:.c=.o)

.PHONY: all run clean 

all: libhtab.a libhtab.so maxwordcount maxwordcount-dynamic tac

# -fPIC: to prevent using static addresses in memory
# Modules of the library
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Static library
libhtab.a: $(OBJS)
	ar rcs $@ $^

# Dynamic library
libhtab.so: $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^

tac.o: tac.c
	$(CC) $(CFLAGS) -c $< -o $@

tac: tac.o
	$(CC) $(CFLAGS) -o $@ $^

# Static linked
maxwordcount: maxwordcount.o libhtab.a
	$(CC) $(CFLAGS) -static -o $@ $^

# Dynamically linked
maxwordcount-dynamic: maxwordcount.o libhtab.so
	$(CC) $(CFLAGS) -o $@ $^ -L. -lhtab


run: maxwordcount
	@echo "Running maxwordcount\n" 
	@echo "Hello this is test hello world" | ./maxwordcount


clean:
	rm -f $(OBJS) maxwordcount maxwordcount-dynamic tac libhtab.a libhtab.so maxwordcount.o tac.o
