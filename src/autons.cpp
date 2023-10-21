#include "main.h"
#include "lemlib/api.hpp"

void nothing() {
    //chassis.moveTo(0, 10, 1000);
    chassis.follow("skills_path.txt", 2000, 15);
    //chassis.turnTo(30, 0, 1000);
    setDriveLights(0x000000);
}

void offense() {

  setDriveLights(0x000000);
}


void defense() {
 
  setDriveLights(0x000000);
}

void skills() {

  setDriveLights(0x000000);
}