#ifndef Ali
#define Ali

#include "Cart_Point.h"
#include "Game_Object.h"
#include "Person.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "Input_Handling.h"

class Alien: public Game_Object
{
	private:
		int attack_strength;
		double range;
		Person * target;
		double speed;
		Cart_Point destination;
		Cart_Vector delta;
		bool isNice;
	public:
		Alien();
		Alien(int in_id,Cart_Point in_loc);
		void start_attack(Person * in_target);
		bool update();
		void show_status();
		void start_moving(Cart_Point dest);
		void stop();
		bool update_location();
		void setup_destination(Cart_Point dest);
		void setSpeed(int value)
		{
			speed=value;
		}
		bool getNice()
		{
			return isNice;
		}
		void setNice(bool value);
		

};






#endif