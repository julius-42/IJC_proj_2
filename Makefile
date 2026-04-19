CC=gcc
CFLAGS=-g -O2 -std=c11 -pedantic -Wall -Wextra

SRCS    = htab_hash_function.c htab_init.c htab_clear.c htab_free.c htab_size.c htab_bucket_count.c
OBJS    = $(SRCS:.c=.o)

.PHONY: all run clean 

all: libhtab.a libhtab.so maxwordcount maxwordcount-shared

# Modules of the library
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Static library
libhtab.a: $(OBJS)
	ar rcs $@ $^

# Dynamic library
libhtab.so: $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^

# Static linked
maxwordcount: maxwordcount.o libhtab.a
	$(CC) $(CFLAGS) -static -o $@ $^

# Dynamically linked
maxwordcount-shared: maxwordcount.o libhtab.so
	$(CC) $(CFLAGS) -o $@ $^ -L. -lhtab


run: maxwordcount
	@echo "Running maxwordcount" 
	@echo "Hello this is test hello world" | ./maxwordcount




clean:
	rm -f $(OBJS) maxwordcount maxwordcount-dynamic libhtab.a libhtab.so
