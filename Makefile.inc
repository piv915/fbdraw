CC = gcc
CFLAGS = -g -Wall
INCFLAGS = -I/usr/include/libdrm -I/usr/include/X11
LDFLAGS = -Wl,-rpath,/usr/local/lib
LIBS = -ldrm -lX11 -lm
