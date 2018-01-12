#ifndef Game_Obj
#define Game_Obj
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;



class Game_Object
{



	protected:
		Cart_Point location;
		int id_num;
		char display_code;
		char state;
	
	public:
		Game_Object(char in_code);
		Game_Object(Cart_Point in_loc, int in_id, char in_code);
		virtual ~Game_Object();
		void drawself(char * ptr);
		char getdispCode()
		{
			return display_code;
		}
		virtual bool is_alive()
		{
			return true;
		}

		Cart_Point get_location()
		{
			return location;
		}

		int get_id()
		{
			//returns an int 
			return id_num;
		}

		char get_state()
		{
			//returns a char
			return state;
		}

		void set_State(char s)
		{
			state=s;
		}

		virtual void show_status();

		virtual bool update()=0;


};

#endif 