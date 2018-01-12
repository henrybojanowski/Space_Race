#include "Alien.h"


Alien::Alien():Game_Object('X')
{
	cout<<"default Alien constructed"<<endl;
	target=NULL;
	speed=5;
	range=2.0;
	attack_strength=2;
	isNice=false;

}
Alien::Alien(int in_id,Cart_Point in_loc):Game_Object(in_loc, in_id, 'X')

{
	cout<<"Alien constructed"<<endl;
	target=NULL;
	speed=5;
	range=2.0;
	if(cart_distance(Cart_Point(0,0),in_loc)>10 )  //different species of aliens that are further away from the origin 
	{
		isNice=true;
	}
	else 
	{
		isNice=false;
	}
	attack_strength=2;	
	
}

void Alien::start_attack(Person * in_target)
{
	// cout<<"location is: "<<location<<endl;
	// cout<<"in_target is: "<<in_target->get_location()<<endl;
	if(isNice)
	{
		throw Invalid_Input("this is a nice Alien! It cannot be commanded to attack an astronaut");
	}
	if(cart_distance(location,in_target->get_location())<=range)
		// if distance from location to target leq range
	{
		target=in_target;
		cout<<display_code<<id_num<<": Smash!"<<endl;
		state='a';
		return; 
	}
	// target=in_target;
	cout<<"Target is out of range"<<endl;

}
bool Alien::update()
{
	// meanAlienCall(); // sets in attack mode if close enough to an astronaut 
					 //if stopped, start moving towards the closest astronaut 
	switch(state)
	{
		case 's':
			return false;
		case 'm':
			// cout<<"Alien update case 'm' called"<<endl;
			// cout<<"in state m"<<endl;
			if(update_location())
			{
				state='s';
				// cout<<"state changed to s"<<endl;
				// show_status();
				return true;
			}
			
			break;
		case 'a':
			
			// cout<<"in case 'a'"<<endl; 
			// cout<<target->get_location()<<endl;
			// double x = cart_distance(get_location(),target->get_location());
			// cout<<"after call to get_location"<<endl;
			if(  (cart_distance(get_location(),target->get_location()) )  >range)
			{
				cout<<"Target out of range"<<endl;
				state='s';
				return true;
			}
			if(cart_distance(get_location(),target->get_location())<=range)
			{
				if(target->get_state()=='x')
				{
					cout<<"I triumph"<<endl;
					state='s';
					return true;
				}
				else 
				{
					cout<<"X"<<get_id() <<": take that!"<<endl;
					target->take_hit(attack_strength);
					return false;
				}
				
			}

			break;
		break;
	}
	return false;
}
void Alien::show_status()
{
	if(getNice())
	{
		cout<<"Nice ";
	}
	else
	{
		cout<<"Mean ";
	}
	cout<<"Alien status: ";
	Game_Object::show_status();
	switch(state)
	{
		case's':
			cout<<"is stopped";
			break;
		case 'a':
			cout<<"is attacking astronaut A"<<target->get_id();
		break;
	}
}

void Alien::start_moving(Cart_Point dest)
{
	// cout<<"Alien start_moving called"<<endl;
	setup_destination(dest);
	state='m';
	cout<<"Moving "<<id_num<<" to "<<dest<<endl;
	cout<<display_code<<id_num<<": On my way."<<endl;
}
void Alien::stop()
{
	state='s';
	cout<<"Stopping("<<id_num<<")"<<endl;
	cout<<display_code<<id_num<<" stopped"<<endl;
}
bool Alien::update_location()
{
	// cout<<"Alien update_location called"<<endl;
	if(fabs(destination.x-get_location().x) <=fabs(delta.x) &&     fabs(destination.y-get_location().y)<=fabs(delta.y) )   
	{
		location.x=destination.x;
		location.y=destination.y;
		cout<<display_code<<get_id()<<": I'm there!"<<endl;
		return true;
	}
	else
	{

		location.x+=delta.x;
		location.y+=delta.y;
		cout<<display_code<<get_id()<<": step..."<<endl;
		return false;
	}
}
void Alien::setup_destination(Cart_Point dest)
{
	// cout<<"Alien setup_destination called"<<endl;
	destination=dest;
	// cout<<"destination is: "<<destination<<endl;
	// cout<<"location is: "<<location<<endl;

	if(destination.x==location.x &&destination.y==location.y)
	{
		delta = Cart_Vector(0,0); 	
	}
	else
	{
		delta = (destination - location) * (speed / cart_distance(destination, location));	
	}
	
}

void Alien::setNice(bool value)
{
	//nice is already set to false
	if(value)
	{
		isNice=true;
	}
}








