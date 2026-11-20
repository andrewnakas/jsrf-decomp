// The light at data_001F963C (only the x and z of its direction).
struct Light_00046920 {
    char unknown_00[0x20];
    float x;
    char unknown_24[4];
    float z;
};

extern Light_00046920 *data_001F963C;

int func_0014C7D0(float x, float z);

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0xc8];
    int angle;

    void func_000C0EF0();
};

// The angle at 0xc8 of the light's direction (func_0014C7D0 of its x and z, plus half a turn); straight along x
// it is -0x4000 for a positive x, 0x4000 for a negative one, else 0.
void Object_000C1270::func_000C0EF0()
{
    Light_00046920 *light = data_001F963C;
    if (light->z != 0.0f) {
        angle = func_0014C7D0(light->x, light->z) + 0x8000;
    } else if (light->x > 0.0f) {
        angle = -0x4000;
    } else if (light->x < 0.0f) {
        angle = 0x4000;
    } else {
        angle = 0;
    }
}
