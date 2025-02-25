#include <stdio.h>
#include <stdlib.h>
#include "..\include\func.h"
#include <locale.h>


int main() {
    char * locale = setlocale(LC_ALL, "ru_RU.UTF-8");
    CarPark park1, park2;
    initCarPark(&park1, 10);
    initCarPark(&park2, 10);
    FILE * output = fopen("output.txt", "w");

    addCar(&park1, "A123BC", "Toyota", 2.0, 180, 5);
    addCar(&park1, "B456DE", "Honda", 1.8, 170, 5);
    addCar(&park1, "C789FG", "Ford", 2.5, 200, 7);

    addCar(&park2, "X987YZ", "BMW", 3.0, 250, 4);
    addCar(&park2, "Y654XW", "Audi", 2.0, 220, 5);


    sortCars(&park1, 0);
    outputCars(stdout, &park1);
    outputCars(output, &park1);

    sortCars(&park2, 1);
    outputCars(stdout, &park2);
    outputCars(output, &park2);

    int result = compareParks(&park1, &park2);
    if (result == 1) {
        printf("Park 1 > park 2\n");
    } else if (result == -1) {
        printf("Park 2 > park 1\n");
    } else {
        printf("Equal\n");
    }

    free(park1.cars);
    free(park2.cars);

    return 0;
}