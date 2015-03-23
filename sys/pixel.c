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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../include/sys/modeset.h"

uint32_t color(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16) | (g << 8) | b;
}

void fbpixel(int unsigned x, int unsigned y, uint32_t color)
{
	unsigned int off;
	struct modeset_dev *iter;
	
	for (iter = modeset_list; iter; iter = iter->next) 
	{
		off = iter->stride * y + x * 4;
		*(uint32_t*)&iter->map[off] = color;
	}
}

void modeset_draw1(void)
{
	uint8_t r, g, b;
	unsigned int i, j, k, off;
	struct modeset_dev *iter;

	srand(time(NULL));
	r = 0xcc;
	g = 0x33;
	b = 0xee;

	for (i = 0; i < 50; ++i) {

		for (iter = modeset_list; iter; iter = iter->next) {
			for (j = 0; j < iter->height; ++j) {
				for (k = 0; k < iter->width; ++k) {
					off = iter->stride * j + k * 4;
					*(uint32_t*)&iter->map[off] =
						     (r << 16) | (g << 8) | b;
				}
			}
		}

		usleep(100000);
	}
}
