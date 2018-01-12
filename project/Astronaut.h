#ifndef Astro 
#define Astro 


#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Person.h"
#include <iostream>



class Astronaut:public Person
{
	private:
		double amount_moonstones;
		double amount_oxygen;
		Oxygen_Depot * depot;
		Space_Station * home;
		bool isAlienHelping;
	public:
		Astronaut();
		Astronaut(int in_id, Cart_Point in_loc);
		~Astronaut();
		bool update();
		void start_supplying(Oxygen_Depot * inputDepot);
		void start_depositing(Space_Station * inputStation);
		void go_to_station(Space_Station * inputStation);
		void show_status();
		
		
};

#endif 
