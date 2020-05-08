
#include "pixel.h"


pixel::pixel()
{
	r = 0;
	g = 0;
	b = 0;
	w = 255;
}

pixel::pixel(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _w)
{
	r = _r;
	g = _g;
	b = _b;
	w = _w;
}