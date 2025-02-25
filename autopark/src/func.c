#include "..\include\func.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void initCarPark(CarPark* park, int capacity) {
    park->cars = (Car*)malloc(capacity * sizeof(Car));
    park->size = 0;
    park->capacity = capacity;
}

void addCar(CarPark* park, const char* number, const char* brand, float engine_volume, int max_speed, int seats) {
    if (park->size >= park->capacity) {
        printf("No capacity\n");
        return;
    }
    Car newCar;
    newCar.id = park->size + 1;
    strncpy(newCar.number, number, NUMBER_SIZE - 1);
    strncpy(newCar.brand, brand, BRAND_SIZE - 1);
    newCar.engine_volume = engine_volume;
    newCar.max_speed = max_speed;
    newCar.seats = seats;
    park->cars[park->size] = newCar;
    park->size++;
}

void sortCars(CarPark* park, int flagSpeed) {
    int i, j;
    Car temp;
    for (i = 0; i < park->size - 1; i++) {
        for (j = 0; j < park->size - i - 1; j++) {
            if ((!flagSpeed && park->cars[j].id > park->cars[j + 1].id) ||
                (flagSpeed && park->cars[j].max_speed > park->cars[j + 1].max_speed)) {
                temp = park->cars[j];
                park->cars[j] = park->cars[j + 1];
                park->cars[j + 1] = temp;
            }
        }
    }
}

void outputCars(FILE * file, CarPark* park) {
    for (int i = 0; i < park->size; i++) {
        fprintf(file, "ID: %d, Number: %s, Mark: %s, engine_volume: %.1f, Max Speed: %d, Capacity: %d\n",
               park->cars[i].id, park->cars[i].number, park->cars[i].brand,
               park->cars[i].engine_volume, park->cars[i].max_speed, park->cars[i].seats);
    }
}

int compareParks(const CarPark* park1, const CarPark* park2) {
    if (park1->size > park2->size) {
        return 1;
    } else if (park1->size < park2->size) {
        return -1;
    }
    return 0;
}