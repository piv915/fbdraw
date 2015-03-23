/***************************************************************************
 *            x11.c
 *
 *  Пн. Март 23 12:32:51 2015
 *  Copyright  2015  piv
 *  <user@host>
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include "../include/sys/x11.h"

Display *dsp;
int screenNumber;
Window win;
GC gc;
long eventMask;
XEvent evt;

int init_x(){

  dsp = XOpenDisplay( NULL );
  if( !dsp ){ return 1; }


  screenNumber = DefaultScreen(dsp);
  unsigned long white = WhitePixel(dsp,screenNumber);
  unsigned long black = BlackPixel(dsp,screenNumber);


  win = XCreateSimpleWindow(dsp,
                               DefaultRootWindow(dsp),
                               50, 50,   // origin
                               800, 600, // size
                               0, black, // border
                               white );  // backgd

  XMapWindow( dsp, win );


  eventMask = StructureNotifyMask;
  XSelectInput( dsp, win, eventMask );

  
  do{
    XNextEvent( dsp, &evt );   // calls XFlush
  } while( evt.type != MapNotify );


  gc = XCreateGC( dsp, win,
                     0,        // mask of values
                     NULL );   // array of values
  XSetForeground( dsp, gc, black );
  return 0;
}

void cleanup_x() {

  eventMask = ButtonPressMask|ButtonReleaseMask;
  XSelectInput(dsp,win,eventMask); // override prev
 
  do{
    XNextEvent( dsp, &evt );   // calls XFlush()
  } while( evt.type != ButtonRelease );


  XDestroyWindow( dsp, win );
  XCloseDisplay( dsp );

}

void xpixel(int unsigned x, int unsigned y, uint32_t color)
{
	XSetForeground( dsp, gc, color );
	XDrawPoint(dsp, win, gc, x, y);
}
