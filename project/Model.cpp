#include <iostream>
#include "Model.h"




Model::Model()
{

	time=0;
	count_down=10;
	compMode=false;

	//astronaut pointers beginning
	Astronaut * A1;
	Astronaut * A2; 
	A1=new Astronaut(1,Cart_Point(5,1));
	A2 = new Astronaut(2,Cart_Point(10,1));


	object_ptrs.push_back(A1);
	object_ptrs.push_back(A2);
	active_ptrs.push_back(A1);
	active_ptrs.push_back(A2);

	person_ptrs.push_back(A1);
	person_ptrs.push_back(A2);
	num_astronauts=2;

	//astronaut pointers end

	//Oxygen_Depot pointers beginning 
	Oxygen_Depot * Oxy1;
	Oxygen_Depot * Oxy2;
	Oxy1 = new Oxygen_Depot(Cart_Point(1,20),1);
	Oxy2 = new Oxygen_Depot(Cart_Point(10,20),2);


	object_ptrs.push_back(Oxy1);
	object_ptrs.push_back(Oxy2);
	active_ptrs.push_back(Oxy1);
	active_ptrs.push_back(Oxy2);

	depot_ptrs.push_back(Oxy1);  
	depot_ptrs.push_back(Oxy2);  


	//Oxygen_Depot pointers ending 

	//Space_Station pointers beginning
	Space_Station * SS1;
	Space_Station * SS2;
	SS1  = new Space_Station(); //default constructor for space station takes no input parameters
	SS2 = new Space_Station(Cart_Point(5,5),2);

	
	object_ptrs.push_back(SS1);
	object_ptrs.push_back(SS2);
	active_ptrs.push_back(SS1);
	active_ptrs.push_back(SS2);

	station_ptrs.push_back(SS1);
	station_ptrs.push_back(SS2);

	//Space_Station pointers ending

	//Alien pointers beginning 
	Alien * Ali1;
	Alien * Ali2;

	
	Ali1=new Alien(1,Cart_Point(7,14));
	
	Ali2=new Alien(2,Cart_Point(7,5));
	


	alien_ptrs.push_back(Ali1);
	alien_ptrs.push_back(Ali2);

	object_ptrs.push_back(Ali1);
	object_ptrs.push_back(Ali2);
	active_ptrs.push_back(Ali1);
	active_ptrs.push_back(Ali2);
	cout<<"Model default constructed"<<endl;
	show_status();


}

Model::~Model()
{
	

	// beginning of alien destructor
	

	for(list <Alien*>:: iterator it=alien_ptrs.begin();it!=alien_ptrs.end();++it)
	{
		
		
		delete *it;
		
	}
	// ending of alien destructor

	// // beginning of depot destructor
	

	for(list <Oxygen_Depot*>:: iterator it1=depot_ptrs.begin();it1!=depot_ptrs.end();++it1)
	{
		
		
		delete *it1;
		
	}
	
	// // ending of depot destructor

	// // beginning of space station destructor
	

	for(list <Space_Station*>:: iterator it2=station_ptrs.begin();it2!=station_ptrs.end();++it2)
	{
		
		
		delete *it2;
		
	}
	

	// // ending of space station destructor

	// // beginning of astronaut destructor
	

	for(list <Person*>:: iterator it3=person_ptrs.begin();it3!=person_ptrs.end();++it3)
	{
		
		
		delete *it3;
		
	}

	// ending of astronaut destructor

	
	cout<<"Model destructed"<<endl;
	

	
}


Person * Model::get_Person_ptr(int id)

{
	
	

	

	for(list<Person*>:: iterator it=person_ptrs.begin();it!=person_ptrs.end();++it)
	{
		if((*it)->get_id()==id)
		{
			return *it;
		}
	}
}

Oxygen_Depot * Model::get_Oxygen_Depot_ptr(int id)
{
	
	

	for(list<Oxygen_Depot*>:: iterator it=depot_ptrs.begin();it!=depot_ptrs.end();++it)
	{
		if((*it)->get_id()==id)
		{
			return *it;
		}
	}
}

Space_Station * Model::get_Space_Station_ptr(int id)
{
	

	list<Space_Station*>::iterator it;

	for(it=station_ptrs.begin();it!=station_ptrs.end();++it)
	{
		if((*it)->get_id()==id)
		{
			return *it;
		}
	}
	

}

Alien * Model::get_Alien_ptr(int id)
{
	
	

	list<Alien*>::iterator it;

	for(it=alien_ptrs.begin();it!=alien_ptrs.end();++it )
	{
		if((*it)->get_id()==id)
		{
			return *it;
		}
	}
}
// void Model::clearMeanAliens()
// {
// 	list<Game_Object*>::iterator it6= active_ptrs.begin();
// 	while(it6!=active_ptrs.end())
		
// 	{
		
		
// 		int aliId = (*it6)->get_id();

// 		if((*it6)->getdispCode()=='X'  && ! ( (get_Alien_ptr(aliId) )->getNice() )) 
// 			//if one is an alien and its a mean alien then clear it from the display 
// 			// because the mean aliens want to hide then attack the astronauts
// 		{
// 			cout<<"in for loop for deletion of aliens "<<endl;
// 			active_ptrs.erase(it6++);
// 			cout<<"after delete call"<<endl;
// 			continue;
// 		}
// 		else
// 		{
// 			// bool call =(*it5)->update();
// 			it6++;
// 		// cout<<"after call"<<endl;
// 			// if(call)
// 			// {
// 			// 	existOutOfLoop =true;
// 			// }

// 		}			
		
// 	}	
// }

bool Model::allAstronautsDead()
{
	list<Person*>::iterator it19;
	for(it19=person_ptrs.begin();it19!=person_ptrs.end();++it19)
	{
		if(((*it19)->get_state())!='x')
		{
			return false;
		}
	}
	return true;
}

bool Model::update()

{



	// cout<<"in model update()"<<endl;
	time+=1;

	if(allAstronautsDead())
	{
		cout<<"all the astronauts are dead!! You Lost!"<<endl;
		exit(1);
	}	
	if(count_down==0)
	{
		//quit the game??
		cout<<"count_down is zero: exiting program"<<endl;
		exit(1);
	}

	bool isUpgraded=true;
	bool everyStationHasOneAstronaut=true;
	int howManyAstronautsMissing=0;
	
	list<Space_Station*>::iterator it1;

	for(it1=station_ptrs.begin();it1!=station_ptrs.end();++it1)
		//find if all the stations are upgraded
			//find if every Space_Station has at least 1 astronaut
			//find if every station has 10 moonstones
			//helps determine if the user has won
	{
		if((*it1)->get_state()!='u')
			//means that the state of the station isnt 'u' or upgraded
		{
			isUpgraded=false;
		}
		if((*it1)->get_astronauts()==0)
		{
			howManyAstronautsMissing++;
			everyStationHasOneAstronaut=false;
		}
	}
	// for(int j=0;j<2;j++)
			
	// {
	// 	if(station_ptrs[j]->get_state()!='u')
	// 		//means that the state of the station isnt 'u' or upgraded
	// 	{
	// 		isUpgraded=false;
	// 	}
	// 	if(station_ptrs[j]->get_astronauts()==0)
	// 	{
	// 		howManyAstronautsMissing++;
	// 		everyStationHasOneAstronaut=false;
	// 	}

		// if(station_ptrs[j]->amount_moonstones<10)
		// {
		// 	everyStationHasTenMoonstones=false;
		// }


	

	bool isLockedIn=true;


	list<Person*>::iterator it2;
	for(it2=person_ptrs.begin();it2!=person_ptrs.end();++it2)
		//find if all the Astronauts are locked into stations
	{
		if((*it2)->get_state()!='l')
		{
			isLockedIn=false;
		}
	}
	if(isUpgraded)
	{
		
		cout<<"Ready for takeoff?? "<<count_down<<"..."<<endl;
		count_down-=1;

		if(!isLockedIn || (isLockedIn && !everyStationHasOneAstronaut))
		{
			cout<<"Missing "<<howManyAstronautsMissing<<" astronauts!"<<endl;
		}
		
		if(isLockedIn &&everyStationHasOneAstronaut)
		{
			cout<<"Blast Off! You Win!"<<endl;
			exit(1);
		}
	}



	

	
	
	//*********below: if the user hasn't won and the count_down isn't zero
	//then decrement count_down and update every object 

	







	// cout<<"before the beef of update()"<<endl;
	bool existOutOfLoop=false;

	depositAliensMoonstones(howManyAliensAreNice());
	if(compMode)
	{
		meanAlienAI();
		cout<<"after meanAlienAI"<<endl;
	}

	//deposit numberOfNiceAliens*1 into each space station 
	
	list<Game_Object*>::iterator it5= active_ptrs.begin();
	while(it5!=active_ptrs.end())
		//call Game_Object::update() on all of the object_ptrs
		//if any of the calls return true, make this function return true
	{
		// cout<<"calls to update in Person/Space_Station/Oxygen_Depot"<<endl;
		// cout<<"in for loop  ";
		// cout<<object_ptrs[i]->get_id();
		if((*it5)->get_state()=='x')
			//if one of the things is dead
		{
			// cout<<"in for loop for deletion of dead pointers"<<endl;
			// cout<<(*it5)->get_id()<<endl;
			// deletePersonPtr((*it5)->get_id());
			// cout<<"after call to deletePersonPtr"<<endl;
			active_ptrs.erase(it5++);

			// cout<<"after delete call"<<endl;
			continue;
		}
		else
		{
			bool call =(*it5)->update();
			it5++;
		// cout<<"after call"<<endl;
			if(call)
			{
				existOutOfLoop =true;
			}

		}			
		
	}
	// cout<<"after for loop"<<endl;

		

	return existOutOfLoop; //if any of the Game_Object::update() calls return true
				//then make this function return true 
				//else return false

	
	


}

// void Model::deletePersonPtr(int id)
// {
// 	list<Person*>::iterator it12;
// 	int count=0;
// 	while(it12!=person_ptrs.end())
// 	{
// 		cout<<"iteration: "<<count<<endl;
// 		count++;
// 		cout<<(*it12)->get_state()<<endl;
// 		cout<<"after call"<<endl;
// 		if((*it12)->get_state()=='x')
// 		{
// 			cout<<"before erase call"<<endl;
// 			person_ptrs.erase(it12++);
// 			cout<<"after erase call"<<endl;
// 			continue;
// 		}
// 		else
// 		{
// 			it12++;
// 		}
// 	}
// }
Person * Model::findClosestAstronaut(Cart_Point loca)
//find the closest astro that isn't lockec in and that isn't dead
{
	bool ison=false;
	list<Person *>::iterator it10;
	double cDist=1000;
	Person * temp;
	for(it10=person_ptrs.begin();it10!=person_ptrs.end();++it10)
	{
		double astroDist=cart_distance(loca,(*it10)->get_location());
		if((*it10)->get_state()=='x' || (*it10)->get_state()=='l')
		{

		}
		else if( (astroDist<cDist )&& ((*it10)->get_state()!='x' || (*it10)->get_state()!='l'))
		{
			ison=true;
			cDist=astroDist;
			temp = (*it10);

		}
	}
	if(!ison)
	{
		return NULL;
	}
	// cout<<"ID of astronaut to attack: "<<(temp)->get_id()<<endl;
	return temp;
}


void Model::meanAlienAI()
{
	list<Alien *>::iterator it9;
	Person * closest;
	Cart_Point closestloc;
	for(it9=alien_ptrs.begin();it9!=alien_ptrs.end();++it9)
		//finds the mean aliens in the alien_ptrs list
			//if in range of an astronaut, start attacking that astronaut
			//if stopped, change to moving to closest astronaut 

	{
		if(   !(  (*it9)->getNice()  )  )  //if its a mean alien 
		{

			closest=findClosestAstronaut((*it9)->get_location());
			// cout<<"id of person tp attack in meanAlienAI: "<<closest->get_id()<<endl;
			if(closest==NULL)
			{
				cout<<"there are currently no Astronauts to attack!"<<endl;
				(*it9)->set_State('s');
				continue;
				
			}

			closestloc = closest->get_location();

			if(   (cart_distance((*it9)->get_location(), closestloc )  <2 ) )
				//if in range of an astronaut 
			{
				(*it9)->start_attack(closest);

			}

			else 
			{
				(*it9)->start_moving(closestloc);
			}
		}
			//if stopped 
		//otherwise it's a nice alien 

	}	
}

bool Model::isActive(int id, char dispCode)
{
	


	if(dispCode=='A')
	{
		list<Person*>::iterator it;

		for(it=person_ptrs.begin();it!=person_ptrs.end();++it)
		{
			if((*it)->get_id()==id )
			{
				return true;
			}
		}
		return false;
	}

	if(dispCode=='X')
	{
		list<Alien*>::iterator it;
		for(it=alien_ptrs.begin();it!=alien_ptrs.end();++it)
		{
			if((*it)->get_id()==id )
			{
				return true;
			}
		}
		return false;
	}

	if(dispCode=='O')
	{
		list<Oxygen_Depot*>::iterator it;
		for(it=depot_ptrs.begin();it!=depot_ptrs.end();++it)
		{
			if((*it)->get_id()==id )
			{
				return true;
			}
		}
		return false;
	}

	if(dispCode=='S')
	{
		list<Space_Station*>::iterator it;
		for(it=station_ptrs.begin();it!=station_ptrs.end();++it)
		{
			if((*it)->get_id()==id )
			{
				return true;
			}
		}
		return false;
	}



}

// void Model::handleAlienAI()
// //only updates the mean aliens because the nice aliens don't do anything besides add moonstones to the space stations
// {
// 	list<Alien *>::iterator it7;
// 	for(it7=alien_ptrs.begin();it7!=alien_ptrs.end();++it7)
// 	{
// 		Cart_Point aliDest=findClosestAstronaut()
// 		(*it7)->start_moving(aliDest);		
// 	}
	
// }
void Model::handle_new_command()
{
	char type;
	int id;
	int ix;
	int iy;


	cin>>type;
	cin>>id;
	cin>>ix; 
	cin>>iy;

	if(cin.fail())
	{
		// cout<<"about to throw"<<endl;
		throw Invalid_Input("you entered the wrong data type");
		// handle_commands(model,view);
	}

	if(id>9)
	{
		throw Invalid_Input("You entered an id that was greater than 9");
	}

	if(type!='a' && type!='x' && type !='s' && type !='d')
	{
		throw Invalid_Input("You type you entered doesn't correspond to an object");
	}
	if(type=='a')
	{
		if(isActive(id,'A'))
		{
			throw Invalid_Input("An astronaut already has this id");
		}
		//else create the new astronaut
		Astronaut *A;
		A= new Astronaut(id,Cart_Point(ix,iy));
		object_ptrs.push_back(A);
		active_ptrs.push_back(A);
		person_ptrs.push_back(A);
		return;
	}

	if(type=='x')
	{
		if(isActive(id,'X'))
		{
			throw Invalid_Input("An alien already has this id");
		}
		//else create the new alien
		Alien * X;
		X= new Alien(id,Cart_Point(ix,iy));
		object_ptrs.push_back(X);
		active_ptrs.push_back(X);
		alien_ptrs.push_back(X);
		return;

	}
	if(type=='s')
	{
		if(isActive(id,'S'))
		{
			throw Invalid_Input("A space station already has this id");
		}
		//else create the new space station
		Space_Station * ss;
		ss= new Space_Station(Cart_Point(ix,iy),id);
		object_ptrs.push_back(ss);
		active_ptrs.push_back(ss);
		station_ptrs.push_back(ss);
		return;
	}
	if(type=='d')
	{
		if(isActive(id,'A'))
		{
			throw Invalid_Input("A depot already has this id");
		}
		//else create the new depot
		Oxygen_Depot * d;
		d= new Oxygen_Depot(Cart_Point(ix,iy),id);
		object_ptrs.push_back(d);
		active_ptrs.push_back(d);
		depot_ptrs.push_back(d);
		return;
	}
}

void Model::display(View &view )
{
	
	view.clear();
	list<Game_Object*>::iterator it;
	for(it=active_ptrs.begin();it!=active_ptrs.end();++it)
	{
		//add a feature at the end so that the aliens aren't displayed on the grid 		
		view.plot(*it);
				
	}
	view.draw();
}


void Model::show_status()
{
	//It outputs the status of all of the Game_Objects by calling their show_status() function
	cout<<"Time: "<<time<<endl;
	list<Game_Object*>::iterator it;
	for(it=object_ptrs.begin();it!=object_ptrs.end();++it)
	{
		//add a feature at the end so that the mean aliens aren't shown 
		(*it)->show_status();
		cout<<" "<<endl;

	}

}

double Model::howManyAliensAreNice()
{
	list<Alien *>::iterator it;
	double count=0;
	for(it=alien_ptrs.begin();it!=alien_ptrs.end();++it)
	{
		if((*it)->getNice())
		{
			count++;
		}
	}
	return count;


}

void Model::depositAliensMoonstones(double number)
{
	list<Space_Station*>::iterator it1;

	for(it1=station_ptrs.begin();it1!=station_ptrs.end();++it1)
	{
		(*it1)->deposit_moonstones(number);
	}
}

void Model::changeGravity(int newValue)
//difference could be negative or positive
{
	list<Person*>::iterator it;

	for(it=person_ptrs.begin();it!=person_ptrs.end();++it)
	{
		(*it)->setSpeed(newValue);
	}

	list<Alien*>::iterator it1;
	for(it1=alien_ptrs.begin();it1!=alien_ptrs.end();++it1)
	{
		(*it1)->setSpeed(newValue);
	}
}



