#include <iostream>

#include "Game_Object.h"

using namespace std;

static bool hasLocation;

Game_Object::Game_Object( char in_code)
{
	location =  Cart_Point(0,0);
	display_code=in_code;
	id_num=1;
	state='s';
	cout<<"Game_Object constructed"<<endl;
	
	
}
Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
	location= Cart_Point(in_loc.x,in_loc.y);
	hasLocation=true;
	display_code=in_code;
	id_num=in_id;
	state='s';
	
	
	cout<<"Game_Object constructed"<<endl;	

}













void Game_Object::show_status()
{

	cout<<display_code<<id_num;
	
	
	
	cout<<" at "<< location; //prints the << overload representation via the previous class 
	
		
	

}

Game_Object::~Game_Object()
{
	cout<<"Game_Object destructed"<<endl;
}

void Game_Object::drawself(char * ptr)
{
	
	
	// char foo[] ={display_code,static_cast<char>(id_num)};

	
	
	// ptr = foo;
	// cout<<"ptr is: "<<*ptr <<" and "<< ptr[1]<<endl;
	
	ptr[0]=display_code;
	ptr[1]='0'+id_num;
	// static_cast<char>(id_num);
	
}




