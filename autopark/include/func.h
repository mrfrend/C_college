#include "struct.h"
#include <stdio.h>
void initCarPark(CarPark* park, int capacity);
void addCar(CarPark* park, const char* license_plate, const char* brand, float engine_volume, int max_speed, int seats);
void sortCars(CarPark* park, int bySpeed);
void outputCars(FILE * file, CarPark* park);
int compareParks(const CarPark* park1, const CarPark* park2);