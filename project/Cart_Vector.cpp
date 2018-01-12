#include "Cart_Vector.h"

#include <iostream>
using namespace std;
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x= inputx;
	y=inputy;
}

Cart_Vector::Cart_Vector()
{
	x=0;
	y=0;
}

// void printValues()
// {
// 	cout<<"x value: "<<this->x<< " y value: "<<this->y<<endl;
// 	return; 
// }

Cart_Vector operator*(const Cart_Vector &v1, double d)
//overload the * symbol 
{
	Cart_Vector justCreated(v1.x, v1.y);

	justCreated.x=v1.x*d;
	justCreated.y=v1.y*d;

	return justCreated;
}

Cart_Vector operator/(const Cart_Vector &v1, double d )
{
	Cart_Vector justCreated(v1.x,v1.y);

	justCreated.x=v1.x/d;
	justCreated.y=v1.y/d;

	return justCreated;
}

ostream& operator<< (ostream &out, const Cart_Vector &v)
{
	out<<"("<<v.x<<","<<v.y<<")";
	return out;
}