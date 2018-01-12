#ifndef Cart_P
#define Cart_P

#include "Cart_Vector.h"
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Cart_Vector;

class Cart_Point
{
	public:
		double x;
		double y;
		Cart_Point();
		Cart_Point(double inputx,double inputy);
			
};

double cart_distance(Cart_Point p1, Cart_Point p2);

Cart_Point operator+(const Cart_Point &p1, const Cart_Point &p2);
Cart_Vector operator-(const Cart_Point &p1, const Cart_Point &p2);
ostream& operator<<(ostream &out, const Cart_Point &p);


#endif 
