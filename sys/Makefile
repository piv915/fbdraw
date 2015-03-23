include ../Makefile.inc

OBJECTS = modeset.o x11.o pixel.o

all: $(OBJECTS)

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -f *.o *~

.PHONY: clean
