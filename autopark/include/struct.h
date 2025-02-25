#define BRAND_SIZE 50
#define LICENSE_SIZE 20

typedef struct {
    int id;
    char license_plate[LICENSE_SIZE];
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