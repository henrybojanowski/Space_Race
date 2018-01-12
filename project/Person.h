#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"






class Person: public Game_Object
{
	public:
		Person();
		virtual ~Person();
		Person(char in_code);
		Person(Cart_Point in_loc , int in_id, char in_code);
		void start_moving(Cart_Point dest);
		void stop();
		void show_status();
		virtual void start_supplying(Oxygen_Depot * inputDepot);
		virtual void start_depositing(Space_Station * inputStation);
		virtual void go_to_station(Space_Station * inputStation);
		bool is_alive();
		void take_hit(int attack_strength);
		void setSpeed(int value)
		{
			speed=value;
		}
	private:
		double speed;
		Cart_Point destination;
		Cart_Vector  delta;
	protected:
		int health;
		bool update_location();
		void setup_destination(Cart_Point dest);

	
};

#endif