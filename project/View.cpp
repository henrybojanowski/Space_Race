#include <iostream>

#include "View.h"


bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	// cout<<"entered get_subscripts"<<endl;
	ix=(location.x-origin.x)/scale;
	iy=(location.y-origin.y)/scale;
	// cout<<location<<endl;
	// cout<<"in get_subscripts() (x,y):"<<ix<<", "<<iy<<endl;
	// cout<<"after declaring ix and iy"<<endl;
	if(ix<=view_maxsize && iy<=view_maxsize)
	{
		return true;
	}
	else
	{
		cout<<"An object is outside the display"<<endl;
		return false;
	}
}

View::View()
{
	size=11; //the number of dots to be produced(there is a dot every other index )   
	scale=2; 
	origin=Cart_Point(0,0);
}
void View::clear()
{
	//for loops organized to go row by row(bottom to top) then go to the next height level (3rd dimension)
	for(int k=0;k<1;k++)
	{
		for(int j=10;j>=0;j--)
		{
			for(int i=0;i<22;i++ )
			{
				if(i%2==0)
					grid[i][j][k]='.';  //even means a dot
				if(i%2!=0)
					grid[i][j][k]=' '; //odd means a space

			}
		}
	}
}
void View::plot(Game_Object *ptr)
{
	int ix=0;
	int iy=0;

	
	
	
	if(     get_subscripts(ix,iy,ptr->get_location())   )
		//now need to actually add this to the grid
	{
		char charPtr[2];
		
		ptr->drawself(charPtr);
		ix=2*ix;
		
		
		if(grid[ix][iy][0]==' ' || grid[ix][iy][0]=='.')
			//statement makes sure there isn't already something in the grid
			//at that specific point
		{
			grid[ix][iy][0]=charPtr[0];
			grid[ix+1][iy][0]=charPtr[1];
		}
		else
		{
			//  view has mutiple objects at the same location
			grid[ix][iy][0]='*';
			grid[ix+1][iy][0]=' ';
		}
	}	
	

}
void View::draw()
//prints the 3d array (but only the 2d representation)  //works for the 2d representation only 
{
	for(int k=0;k<1;k++)
	{
		for(int j=10;j>=0;j--)
		{
			if(j%2==0)
			{
				if(j*2<10)
					cout<<j*2<<" ";
				else
					cout<<j*2;
			}
			if(j%2!=0)
			{
				cout<<"  ";
			}
			for(int i=0;i<22;i++ )
			{
				cout<<grid[i][j][k];
			}
			cout<<" "<<endl; //add another line at the end
		}
	}
	cout<<"  0   4   8   12  16  20"<<endl;
}



