/***************************************************************************
 *            draw.c
 *
 *  Пн. Март 23 05:10:46 2015
 *  Copyright  2015  piv
 *  <user@host>
 ****************************************************************************/
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of piv nor the name of any other
 *    contributor may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY piv AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL piv OR ANY OTHER
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "pixel.h"
#include "draw.h"
#include <math.h>

void draw_circle(int x, int y, int radius, uint32_t color)
{
	double angle, xk, yk;

	for(angle = 0; angle <= 2*M_PI; angle = angle + 0.0001) {
		xk = cos(angle) * radius;
		yk = sin(angle) * radius;

		pixelc(xk + x , yk + y, color);
	}
}

void draw_circle_fill(int x, int y, int radius, uint32_t color)
{
	double angle, xk, yk;

	for(angle = 0; angle <= 2*M_PI; angle = angle + 0.0001) {
		xk = cos(angle) * radius;
		yk = sin(angle) * radius;

		draw_line(x,y, xk + x , yk + y, color);
	}
}


void draw_line(int x1, int y1, int x2, int y2, uint32_t color)
{
	int w,h,i,j, is, js;
	float k;
	
	w = x2 - x1;
	h = y2 - y1;
	k = (float)(h < w ? h : w) / (float)(h < w ? w : h);
	
	// long side
	for(i = 0; i <= (h < w ? w : h); i++) 
	{
		// short side
		j = ceil( i * k );

		if ( h < w ) {
			pixelc(x1 + i, y1 + j, color);
		}
		else {
			pixelc(x1 + j, y1 + i, color);
		}
	}
}

void draw_rectangle(int x1, int y1, int x2, int y2, uint32_t color)
{
	int x, y;
	for(x = x1; x <= x2; x++) {
		pixelc(x,y1,color);
		pixelc(x,y2,color);
	}
	
	for(y=y1; y<=y2; y++) {
		pixelc(x2,y,color);
		pixelc(x1,y,color);
	}

}

///////////////////////////////////////////////////////////////////////////////
void draw(void)
{
	draw_rectangle(100, 100, 600, 600, color(0x00, 0x00, 0x00));
	draw_line(100, 100, 600, 600, color(0xff, 0x00, 0x00));
	draw_circle(350,350,100, color(0xff, 0x00, 0x00));
	draw_circle_fill(800,350,100, color(0xff, 0xff, 0x00));
}

