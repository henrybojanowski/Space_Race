#ifndef Mod
#define Mod 
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Person.h"
#include "Astronaut.h"
#include "View.h"
#include "stdlib.h"
#include "Alien.h"
#include "Input_Handling.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctime>





class Model 
{

	private:
		int time;
		int count_down;
		bool compMode;
		
		list<Game_Object*> object_ptrs;
		list <Game_Object*> active_ptrs;
		list<Person*> person_ptrs;
		list<Oxygen_Depot*> depot_ptrs;
		list<Space_Station*> station_ptrs;
		list<Alien*> alien_ptrs;
	public:
		Model();
		~Model();
		bool isActive(int id, char dispCode);
		Person *get_Person_ptr(int id);
		Oxygen_Depot * get_Oxygen_Depot_ptr(int id);
		Space_Station * get_Space_Station_ptr(int id);
		Alien * get_Alien_ptr(int id);
		bool update();
		void display(View &view );
		void show_status();
		int num_astronauts; //has the number of astronauts, increment within model
		// Game_Object * find_pointer(int id, linked_list ll);
		void handle_new_command();
		void changeGravity(int newValue);
		double howManyAliensAreNice();
		void depositAliensMoonstones(double number);
		void meanAlienAI();
		Person * findClosestAstronaut(Cart_Point loca);
		bool allAstronautsDead();
		// void deletePersonPtr(int id);
		bool getCompMode()
		{
			return compMode;
		}
		void setMode(char c  )
		{
			if(c=='c')
			{
				compMode=true;
			}
		}
		
};








#endif




