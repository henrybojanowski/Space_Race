//for the explanation of the extra credit, please read the cout statements or just run the program
//From a software engineering perspective, I deemed this to be a better way to explain the game
//I only did part 7, I did not do part 6
#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;



int main() 
{
	
    cout<<"EC327: Introduction to Software Engineering programming assignment 4"<<endl;
    cout<<"Fall 2017"<<endl;

    cout<<"PLEASE PAUSE and read the following new instructions for the game: "<<endl;
    cout<<" "<<endl;
    cout<<"Explanation of the new game(new feature is type of Aliens): "<<endl;
    cout<<"      'Nice' Aliens are defined as aliens 10 Cart_Point or further from the origin(0,0)"<<endl;
    cout<<"      they cannot be commanded to attack Astronauts, rather they help Astronauts by adding moonstones to all the space stations"<<endl;
    cout<<"      'Mean' Aliens are the usual Aliens that can be commanded to attack Astronauts, they are defined as Aliens within 10 Cart_Points from the origin"<<endl;
    cout<<"In computer mode(AI): "<<endl;
    cout<<"       Mean Aliens will move towards the closest Astronaut(unless Astronaut is locked into a station or dead) and attack them until they're dead"<<endl;
    cout<<"       Mean Aliens will then move towards the next Astronaut and attempt to kill it until there are 0 Astronauts left"<<endl;
    cout<<"       Nice aliens will still deposit moonstones to space stations, for every 1 nice Alien, 1 moonstone will be deposited into every space station"<<endl;
    cout<<"Gravity Explanation: "<<endl;
    cout<<"        the gravity is changed approximately 20 percent of the time "<<endl;
    cout<<"        depending on random number generation, the gravity can either be increased to 8 or decreased to 3"<<endl;
    cout<<"        the gravity is then randomly changed back to 5 the next time the random number generator returns true"<<endl;
    cout<<" "<<endl;

    char mode;
    
    

    while(true)
    {
        cout<<"Would you like to enter Normal mode (n) or Computer mode (c) ";
        cin>>mode;
        if(mode=='c'|| mode=='n')
        {
            break;
        } 
        else
        {
            cout<<"that wasn't a 'c' or an 'n' try again "<<endl;
        }   
    }

    View v;

    Model m;
    
	m.setMode(mode); //just sets program to either computer or normal mode

	
    
    
    
    
    m.display(v); //displays the board for the first time

    handle_commands(m,v); //handles all commands and will handle re-displaying the board
    
    
    
}




