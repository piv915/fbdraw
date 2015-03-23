
## Created by Anjuta

CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o pixel.o draw.o modeset.o
INCFLAGS = -I/usr/include/libdrm
LDFLAGS = -Wl,-rpath,/usr/local/lib
LIBS = -ldrm -lm

all: main

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

clean:
	rm -f *.o

.PHONY: all
.PHONY: count
.PHONY: clean
