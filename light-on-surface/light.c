#include <stdio.h>
#include <math.h>

// STEP 1: Define positions
#define FAN_POSITION_X 65.0
#define FAN_POSITION_Y 0.0
#define FAN_POSITION_Z 0.0

#define FLASHLIGHT_POSITION_X 0.0
#define FLASHLIGHT_POSITION_Y 0.0
#define FLASHLIGHT_POSITION_Z 0.0

#define LIGHT_INTENSITY 1.0

int main() {
    // STEP 2: Find direction from flashlight to fan
    double direction_x = FAN_POSITION_X - FLASHLIGHT_POSITION_X;
    double direction_y = FAN_POSITION_Y - FLASHLIGHT_POSITION_Y;
    double direction_z = FAN_POSITION_Z - FLASHLIGHT_POSITION_Z;

    // STEP 3: Calculate distance
    double distance = sqrt(direction_x * direction_x + 
                          direction_y * direction_y + 
                          direction_z * direction_z);

    // STEP 4: Normalize direction
    direction_x /= distance;
    direction_y /= distance;
    direction_z /= distance;

    // STEP 5: Define surface normal (which way fan faces)
    double surface_normal_x = 1.0;
    double surface_normal_y = 0.0;
    double surface_normal_z = 0.0;

    // STEP 6: Calculate dot product (how directly light hits)
    double dot_product = direction_x * surface_normal_x + 
                         direction_y * surface_normal_y + 
                         direction_z * surface_normal_z;

    // STEP 7: Calculate distance factor (inverse square law)
    double distance_factor = 1.0 / (distance * distance);

    // STEP 8: Calculate final brightness
    double brightness = LIGHT_INTENSITY * fmax(dot_product, 0.0) * distance_factor;


    printf("Distance to fan: %f\n", distance);
    printf("Dot product: %f\n", dot_product);
    printf("Distance factor: %f\n", distance_factor);
    printf("Final brightness: %f\n", brightness);

    return 0;
}