#define BRAND_SIZE 50
#define NUMBER_SIZE 10

typedef struct {
    int id;
    char number[NUMBER_SIZE];
    char brand[BRAND_SIZE];
    float engine_volume;
    int max_speed;
    int seats;
} Car;

typedef struct {
    Car* cars;
    int size;
    int capacity;
} CarPark;