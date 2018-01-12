#include <iostream>


#include "Oxygen_Depot.h"

using namespace std;

static bool haslocation;	

Oxygen_Depot::Oxygen_Depot(): Game_Object('O')
{

	id_num=1;
	amount_oxygen=50; 
	display_code='O'; 
	state='f';
	cout<<"Oxygen_Depot default constructed"<<endl;
}
Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId) : Game_Object( inputLoc, inputId, 'O')
{
	amount_oxygen=50;

	id_num=inputId;
	location=inputLoc;
	state='f';
	display_code='O';
	//shouldn't need to re-declare anything like the state? 
	cout<<"Oxygen_Depot constructed"<<endl;

}

bool Oxygen_Depot::is_empty()
{
	if(amount_oxygen==0)
	{
		return true;
	}
	else
		return false;
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	if(amount_oxygen>=amount_to_extract)
	{
		amount_oxygen=amount_oxygen-(amount_to_extract);
		return amount_to_extract;
	}

	else
	{

		double dummy_ret=amount_oxygen;
		amount_oxygen=0;
		return dummy_ret;
	}
}

bool Oxygen_Depot::update()
{
	if(is_empty() && state!='e')
	{
		state='e';
		display_code='o';
		cout<<"Oxygen_Depot "<<id_num<<" has been depleted"<<endl;
		return true; 
	}
	else
	//state is already e or it is not empty  
	{
		// cout<<"state was already e or it's not empty"<<endl;
		return false;
	}

} 

void Oxygen_Depot::show_status()
{
	cout<<"Oxygen Depot status: ";
	Game_Object::show_status();
	cout<<" contains "<<amount_oxygen;

}
Oxygen_Depot::~Oxygen_Depot()
{
	cout<<"Oxygen_Depot destructed"<<endl;
}


