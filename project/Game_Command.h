#ifndef GC
#define GC

#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <limits>
// extern bool errorCalled;
extern bool speedNot5;
void handle_commands(Model &model, View &view);

void do_go_command(Model &model, View &view);
void do_run_command(Model &model, View &view);
void do_lock_in_station(Model &model,View &view);
void do_move_command(Model &model, View &view);
void do_work_depot_command(Model &model, View &view);
void do_deposit_moonstones(Model &model, View &view);
void do_stop_astronaut(Model &model);
void do_attack_command(Model &model);
void do_change_gravity(Model &model);







#endif