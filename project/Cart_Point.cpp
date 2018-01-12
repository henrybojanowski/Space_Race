#include <iostream>
#include "Cart_Point.h"



using namespace std;


	
Cart_Point::Cart_Point()
{
	// cout<<"CART_POINT default constructor called"<<endl;
	x=0;
	y=0;
}
Cart_Point::Cart_Point(double inputx,double inputy)
//constructor initializes values
{
	// cout<<"CART_POINT initializer called"<<endl;
	x=inputx;
	y=inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
//non-member functions that takes in objects of the class as paramters
{
	double p2X=p2.x;
	double p1X=p1.x;

	double p2Y= p2.y;
	double p1Y= p1.y;

	double xValue= pow((p2X-p1X),2);
	double yValue= pow((p2Y-p1Y),2);

	return sqrt(xValue+yValue);


}

	



Cart_Point operator+ (const Cart_Point &p1, const Cart_Vector &v1 )
	{
		const Cart_Point justCreated((p1.x+v1.x),(p1.y+v1.y) );
		
		return justCreated;
	}
Cart_Vector operator- (const Cart_Point &p1, const Cart_Point &p2 )
	{
		const Cart_Vector justCreated((p1.x-p2.x),(p1.y-p2.y) );
		
		return justCreated;
	}

ostream& operator<< (ostream &out, const Cart_Point &p)
{
	out<<"("<<p.x<<","<<p.y<<") ";
	return out;
}