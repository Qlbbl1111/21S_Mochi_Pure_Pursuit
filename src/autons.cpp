#include "main.h"
#include "lemlib/api.hpp"

void nothing() {
    //chassis.moveTo(0, 10, 1000);
    chassis.follow("path.txt", 2000, 15);
    //chassis.turnTo(30, 0, 1000);
    setLights(0x000000);
}

void offense() {

  setLights(0x000000);
}


void defense() {
 
  setLights(0x000000);
}

void skills() {

  setLights(0x000000);
}