#include "main.h"


void setLights(int hex) {
    leftDriveLights.set_all(hex);
    rightDriveLights.set_all(hex);
}