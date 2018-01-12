#ifndef Oxy_Dep
#define Oxy_Dep

#include <iostream>
#include "Game_Object.h"



class Oxygen_Depot: public Game_Object
{
	private:
		double amount_oxygen;
	public:
		Oxygen_Depot();
		~Oxygen_Depot();
		void show_status();
		Oxygen_Depot(Cart_Point inputLoc, int inputId);
		bool is_empty();
		double extract_oxygen(double amount_to_extract= 20.0);
		bool update();

};


#endif
