/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void person_tests();
void elevator_tests();
void file_check();

void start_tests() {
    // call your test functions here
    person_tests();
    elevator_tests();
    //file_check();
    return;
}

// write test functions here
void person_tests() {
    //initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;
    //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 0" << endl;
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
    //simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);
    //no change
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
    p.tick(TICKS_PER_ANGER_INCREASE); //7 after
    p.tick(TICKS_PER_ANGER_INCREASE); //8 after
    p.tick(TICKS_PER_ANGER_INCREASE); //9 after
    exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 1" << endl;
    
    //second person
    Person p2("11f8t11a6");
    cout << p2.getTurn() << " " << p2.getCurrentFloor() << " " << p2.getTargetFloor() << " " << p2.getAngerLevel() << endl;
    //tick
    bool exploded2 = p2.tick(1);
    cout << exploded2 << " Expected 0" << endl;
    cout << p2.getTargetFloor() << " " << p2.getAngerLevel() << endl;
    exploded2 = p2.tick(3);
    cout << exploded2 << " Expected 0" << endl;
    p2.tick(TICKS_PER_ANGER_INCREASE + 5);
    cout << exploded2 << " Expected 1" << endl;
    
}

void elevator_tests() {
    // NOTE - there is an Elevator::print function!
    // this will not find any of the bugs for the lab assignment
    
    Elevator e1;
    e1.tick(5);
    e1.serviceRequest(9);
    e1.print(cout);
    
    Elevator e2;
    e2.serviceRequest(11);
    e2.tick(0);
    e2.print(cout);
    
    Elevator e3;
    e3.tick(-3);
    e3.serviceRequest(-1);
    e3.print(cout);
    
    Elevator e4;
    e4.serviceRequest(8);
    e4.tick(7);
    e4.print(cout);
    
    Elevator e5;
    e5.serviceRequest(3);
    e5.tick(3);
    e5.print(cout);
    return;
}
