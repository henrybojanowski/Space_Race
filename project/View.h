#ifndef V
#define V

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Astronaut.h"
const int view_maxsize=20;


class View 
{
	private:
		int size;
		double scale;
		Cart_Point origin;
		char grid[view_maxsize+1][view_maxsize+2][2];
		bool get_subscripts(int &ix, int &iy, Cart_Point location);
	public:
		View();
		void clear();
		void plot(Game_Object *ptr);
		void draw();



};



#endif

