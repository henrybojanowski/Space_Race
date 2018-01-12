#include <iostream>
#include "Astronaut.h"

using namespace std;

Astronaut::Astronaut():Person('A')
{
	amount_moonstones=0;
	amount_oxygen=20;
	depot=NULL;
	home=NULL;
	cout<<"Astronaut default constructed"<<endl;

}
Astronaut::Astronaut(int in_id, Cart_Point in_loc) :Person(in_loc,in_id,'A')
{
	amount_moonstones=0;
	amount_oxygen=20;
	depot=NULL;
	home=NULL;
	cout<<"Astronaut constructed"<<endl;
}

bool Astronaut::update()
{
	double justExtracted=0;

	switch(Game_Object::get_state() )
	{
		case 's':
			
			break;
		case 'm':
			
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			// cout<<"in state m"<<endl;
			if(update_location())
			{
				state='s';
				// cout<<"state changed to s"<<endl;
				// show_status();
				return true;
			}
			amount_oxygen-=1;
			amount_moonstones+=1;  //do these two things bc update_location() returns false
			
			
			break;
		case 'o':
			
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			if(update_location())
			{
				// cout<<"in case 'o' and update_location returns true "<<endl;
				state='g';
				// cout<<"state changed to 'g' "<<endl;
				return true;
			}
			else
			{
				//stay in the outbound state
			}
			amount_oxygen-=1;
			amount_moonstones+=1;  //do these two things bc update_location() returns false
			break;
		case 'g':
			// cout<<"in state is g "<<endl;
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			justExtracted +=depot->extract_oxygen();
			cout<<display_code<<id_num<<": Got "<<justExtracted<<" more oxygen"<<endl;
			amount_oxygen+=justExtracted;
			state='s';
			return true;
			
			break;
		case 'i':
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			
			if(update_location())
			{
				// cout<<"update_location returns true and state changed to 'd' "<<endl;	
				state='d';
				return true;
			}
			amount_oxygen-=1;
			amount_moonstones+=1;  //do these two things bc update_location() returns false
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			break;
		case 'd':
		//depositing moonstones
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			cout<<display_code<<id_num<<": Deposit "<<amount_moonstones<<" moonstones"<<endl;
			home->deposit_moonstones(amount_moonstones);
			// cout<<"after using the home pointer in case 'd' "<<endl;
			amount_moonstones=0;
			state='s';
			return true;
			
			break;
		case 'l':
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}
			
			if(location.x!=(home->get_location()).x || location.y!=(home->get_location()).x)
			{
				if(update_location())
				{
					
					home->add_astronaut();
					return true;
				}
			
			}

				
			amount_oxygen-=1;
			amount_moonstones+=1;  //do these two things bc update_location() returns false
			break;
		case 'x':
			if(state=='x')
			{
				return false;
			}

			if(health<3)
			{
				state=state+32;
			}
			if(amount_oxygen==0)
			{
				cout<<"I can't move, I'm out of oxygen"<<endl;
				state='x';
				return true;
			}	
	break;

	}
	return false;
}
void Astronaut::start_depositing(Space_Station * inputStation)
{
	
	// start_moving(inputStation->get_location()); //do i need to call start_moving in Person class first?

	// inputStation->deposit_moonstones(amount_moonstones);
	if(state!='x')
	{
		Person::setup_destination(inputStation->get_location());
		home=inputStation;
		state='i';
		cout<<"Astronaut "<<id_num<<" depositing to Space Station "<<home->get_id()<<endl;
		cout<<display_code<<id_num<<": Yes, my lord"<<endl;
		return;
	}
	cout<<"I can't move, I'm dead."<<endl;

}

void Astronaut::start_supplying(Oxygen_Depot * inputDepot)

{
	if(state!='x')
	{
		setup_destination(inputDepot->get_location());
		depot=inputDepot;
		state='o';
		cout<<"Astronaut "<<id_num<<" supplying from Oxygen Depot "<<depot->get_id()<<endl;
		cout<<display_code<<id_num<<": Yes, my lord"<<endl;
		return;
	}
	cout<<"I can't move, I'm dead."<<endl;

}

void Astronaut::go_to_station(Space_Station * inputStation)
{
	if(state!='x')
	{
		home=inputStation;
		state='l';
		// inputStation->update();
		// inputStation->add_astronaut();
		cout<<"Astronaut "<<id_num<< " locking in at Space Station "<<inputStation->get_id()<<endl;
		setup_destination(inputStation->get_location());
		return;
	}
	
	cout<<"I can't move, I'm dead."<<endl;
}

void Astronaut::show_status()
{
	
	cout<<"Astronaut status: ";
	Person::show_status();
	switch(Game_Object::get_state() )
	{
		case 's':
			cout<<" is stopped with "<<amount_oxygen<<" oxygen and "<<amount_moonstones<<" moon stones";
			break;
		case 'm':
			break;
		case 'o':
			cout<<" is outbound to a Depot with "<<amount_oxygen<<" oxygen and "<<amount_moonstones<<" moonstones";
			break;
		case 'g':
			cout<<" is getting oxygen from depot";
			break;
		case 'i':
			cout<<" is inbound to home with load: "<<amount_moonstones<<" moonstones and "<<amount_oxygen<<" oxygen";
			break;
		case 'd':
			cout<<" is depositing "<<amount_moonstones<<" moon stones";
			break;
		case 'l':
			if(amount_oxygen==0)
			{
				cout<<" is out of oxygen "<<endl;
			}
			else
				cout<<" is locked at Space Station";
			break;


	}
}

Astronaut::~Astronaut()
{
	cout<<"Astronaut destructed"<<endl;
}




