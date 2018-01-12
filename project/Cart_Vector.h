#ifndef Cart_V 
#define Cart_V
#include <iostream>

using namespace std;


class Cart_Vector
{
	public:
		double x;
		double y;
		Cart_Vector();
		Cart_Vector(double inputx, double inputy);
	// void printValues();	

	
};

Cart_Vector operator* (const Cart_Vector &v1, double d) ;
Cart_Vector operator/(const Cart_Vector &v1, double d);
ostream& operator<<(ostream &out, const Cart_Vector &v);	

#endif