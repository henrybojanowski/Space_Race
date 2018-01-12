#include "Space_Station.h"






Space_Station::Space_Station(): Game_Object( 's')
{
	display_code='s';
	state='o';
	id_num=1;
	amount_moonstones=0;
	number_astronauts=0;
	cout<<"Space_Station default constructed"<<endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId) : Game_Object(inputLoc, inputId, 's')
{
	display_code='s';
	amount_moonstones=0;
	number_astronauts=0;
	location=inputLoc;
	id_num=inputId;
	cout<<"Space_Station constructed"<<endl;


}
void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones+=deposit_amount;
	return;
}
bool Space_Station::add_astronaut()

{
	//only increment if status is upgraded
	if(state=='u')
	{
		number_astronauts+=1;
		return true; 

	}
	else
	{
		return false;
	}
	
}

int Space_Station::get_astronauts()
{
	return number_astronauts;
}
bool Space_Station::update()
{
	if(amount_moonstones>=10 && state!='u')
	{
		state='u';
		display_code='S';
		cout<<display_code<<id_num<<" has been upgraded"<<endl;
		return true;
	}
	return false;

}
void Space_Station::show_status()
{
	cout<<"Space Station status: ";
	Game_Object::show_status();
	cout<<"contains: "<<amount_moonstones<<" moon stones and contains "<<number_astronauts<<" astronauts.";
	if(state=='u')
		cout<<" station is upgraded!";
	else
		cout<<" not yet upgraded";
	return;
}

Space_Station::~Space_Station()
{
	cout<<"Space_Station destructed"<<endl;
}
