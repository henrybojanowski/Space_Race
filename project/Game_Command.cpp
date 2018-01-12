#include "Game_Command.h"
bool speedNot5;

void do_move_command(Model &model, View &view)
{
	int id;
	
	
	cin>>id;
	

	double inputX;
	cin>>inputX;




	double inputY;
	cin>>inputY;
	// cout<<"in do move command"<<endl;



	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	
	
	}

	// cout<<"after the while loop"<<endl;


	
	
	char alienOrAstronaut;

	cout<<"Move Astronaut (enter 'a') or Alien (enter 'x') ";
	cin>>alienOrAstronaut;
	if(alienOrAstronaut!='a' && alienOrAstronaut!='x')
	{
		throw Invalid_Input("you didn't enter an 'a' or an 'x' ");
	}
	if(alienOrAstronaut=='x' && model.getCompMode())
	{
		throw Invalid_Input("you cannot move an alien!");
	}
	if(!model.isActive(id,(alienOrAstronaut-32)))
		//if they call like A100 or X100 and that doesn't exist
	{
		if(alienOrAstronaut=='a')
		{
			throw Invalid_Input("that astronaut doesn't exist");
		}
		throw Invalid_Input("that alien doesn't exist");
	}

	if(alienOrAstronaut=='a')
		//user entered an astronaut
	{	if(inputX==model.get_Person_ptr(id)->get_location().x  
			&& inputY==model.get_Person_ptr(id)->get_location().y)
		{
			cout<<"Moving "<<id<<" to ("<<inputX<<","<<inputY<<")"<<endl;
			cout<<'A'<< id<<": Im already there. see?"<<endl;
			model.display(view);
			return;
		}
		model.get_Person_ptr(id)->start_moving(Cart_Point(inputX,inputY));
		// cout<<"*******after call to start_moving"<<endl;
		// model.display(view);
		return;
	}
	else
		//user entered an Alien
	{
		if(inputX==model.get_Alien_ptr(id)->get_location().x  
			&& inputY==model.get_Alien_ptr(id)->get_location().y)
		{
			cout<<"Moving "<<id<<" to ("<<inputX<<","<<inputY<<")"<<endl;
			cout<<'X'<< id<<": Im already there. see?"<<endl;
			model.display(view);
			return;
		}
		
		model.get_Alien_ptr(id)->start_moving(Cart_Point(inputX,inputY));
		// model.display(view);
		return;
	}
}

void do_work_depot_command(Model &model, View &view)
{
	int astroID;
	int odID;
	cin>>astroID;
	cin>>odID;

	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	}

	if(!model.isActive(astroID,'A'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that astronaut doesn't exist");
	}
	if(!model.isActive(odID,'O'))
	{
		throw Invalid_Input("that depot doesn't exist");
	}


	model.get_Person_ptr(astroID)->start_supplying(model.get_Oxygen_Depot_ptr(odID));
	model.display(view);
}

void do_deposit_moonstones(Model &model, View &view)
{
	int astroID;
	int ssID;
	cin>>astroID;
	cin>>ssID;
	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	}

	if(!model.isActive(astroID,'A'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that astronaut doesn't exist");
	}
	if(!model.isActive(ssID,'S'))
	{
		throw Invalid_Input("that space station doesn't exist");
	}

	
	model.get_Person_ptr(astroID)->start_depositing(model.get_Space_Station_ptr(ssID));
	model.display(view);

}

void do_stop_astronaut(Model &model)
{
	int astroID;
	cin>>astroID;
	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	}
	if(!model.isActive(astroID,'A'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that astronaut doesn't exist");
	}


	model.get_Person_ptr(astroID)->stop();
}

void do_lock_in_station(Model &model, View &view)
{
	int astroID;
	int ssID;
	cin>>astroID;
	cin>>ssID;

	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	}

	if(!model.isActive(astroID,'A'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that astronaut doesn't exist");
	}
	if(!model.isActive(ssID,'S'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that space station doesn't exist");
	}
	model.get_Person_ptr(astroID)->go_to_station(model.get_Space_Station_ptr(ssID));
	model.display(view);

}

void do_go_command(Model &model, View &view)
//"go": advance one time step by updating each object once.
{
	// cout<<"in do_go_command"<<endl;
	model.update();
	// cout<<"after update() command "<<endl;
	model.show_status();
	// cout<<"after show_status() command "<<endl;
	model.display(view);

}
void do_run_command(Model &model, View &view)
{
	int maxSteps=5;
	while(maxSteps>0)
	{
		do_change_gravity(model);
		// cout<<"in Game_Command::do_run_command()"<<endl;
		bool modelUpdateCall=model.update();
		// cout<<"in Game_Command::after the model.update() call "<<endl;
		if(modelUpdateCall)
		{
			break;
		}
		maxSteps--;
	}
	model.show_status();
	model.display(view);

	
}

void do_attack_command(Model &model)
//apparently supposed to check for error inputs
//could be a lot to check for 
{
	if(model.getCompMode())
	{
		throw Invalid_Input("You are in computer mode! you cannot command  this!");
	}
	int alienID;
	int astroID;
	cin>>alienID;
	cin>>astroID;

	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);


	}
	
	if(!model.isActive(alienID,'X'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that alien doesn't exist");
	}
	if(!model.isActive(astroID,'A'))
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("that astronaut doesn't exist");
	}

	if((model.get_Person_ptr(astroID))->get_state()=='x')
	{
		throw Invalid_Input("That Astronaut is already dead!");
	}


	model.get_Alien_ptr(alienID)->start_attack(model.get_Person_ptr(astroID));

}

void do_change_gravity(Model &model) //gets called via calling commands 'g' and 'r' (called indirectly)
{
	    // srand(time(NULL));
		int number= rand() %10+1;
		if(number==4 || number==6)
		{
			if(speedNot5)
			{
				//change it back 
				speedNot5=false;
				model.changeGravity(5);
			}
			else if(number==4)
			{
				
				speedNot5=true;
				model.changeGravity(2);

			}
			else if(number==6)
			{
				speedNot5=true;
				model.changeGravity(8);
			}

			cout<<"gravity has been altered!!"<<endl;
		}
}

void handle_commands(Model &model, View &view)
{

	
	speedNot5=false;	
	while(true)
	{
		
		
		cout<<"Enter command: ";
		char inputCommand;
		cin>>inputCommand;
		try
		{
			// cout<<"inputCommand: "<<inputCommand<<endl;
			switch(inputCommand)
			{
				case 'a':
					do_attack_command(model);
					break;
				case 'm':
					do_move_command(model, view);
					break;
				case 'w':
					do_work_depot_command(model, view);
					break;
				case 'd':
					do_deposit_moonstones(model,view);
					break;
				case 's':
					do_stop_astronaut(model);
					break;
				case 'l':
					do_lock_in_station(model, view);
					break;
				case 'g':
					cout<<"Advancing one tick"<<endl;
					do_change_gravity(model);
					do_go_command(model,view);
					break;
				case 'n':
					model.handle_new_command();	
					break;
				case 'r':
					cout<<"Advancing to next event"<<endl;
					do_run_command(model,view);
					
					break;
				case 'q':
					cout<<"Terminating program "<<endl;
					return;
					 //return here destroys all the objects, better than using an exit() function
				default:
					cout<<"About to throw in default "<<endl;
					throw Invalid_Input("that isn't a command ");
				
				
			}
		// cout<<"before show_status in Game_Command"<<endl;
		// model.show_status();
		// cout<<"*****after switch statement"<<endl;
		}
		//outside try block
		catch(Invalid_Input &except)
		{
			
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			
			
			
			
			

			

			cout<<"Invalid input - "<<except.msg_ptr<<endl;
			cout<<"(enter the whole command again) ";
			
			
			
			
		}
		// cout<<"after the catch block"<<endl;
		// catch(int x)
		// {
		// 	cout<<"entered the wrong type"<<endl;
		// 	handle_commands(model,view);
		// 	return;	
		// }
		// catch(...)
		// {
		// 	cout<<"General: incorrect input"<<endl;
		// }
		
	}
}


