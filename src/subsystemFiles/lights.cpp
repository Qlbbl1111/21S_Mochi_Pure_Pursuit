#include "main.h"


void setDriveLights(int hex) {
    leftDriveLights.set_all(hex);
    rightDriveLights.set_all(hex);
}

void setWingLights(int hex) {
    leftWingLights.set_all(hex);
    rightWingLights.set_all(hex);
}