include Makefile.inc

DIRS	= sys
OBJECTS = $(patsubst %.c, %.o, $(shell find . -name '*.c'))
TARGET  = main

all: $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -f *.o *~ $(TARGET)
	$(MAKE) -C $(DIRS) clean

.PHONY: all
.PHONY: clean
