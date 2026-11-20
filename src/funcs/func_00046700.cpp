struct Vector3 {
    float x;
    float y;
    float z;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    Light_00046920 lights[5];
    int count;
    char unknown_234[0x40];
    Light_00046920 *current;
    Light_00046920 *top;

    void func_00046700(const Light_00046920 *light);
};

// Replaces the light on top of the stack with a copy and makes it the current one.
void Object_00046670::func_00046700(const Light_00046920 *light)
{
    lights[count] = *light;
    current = top = &lights[count];
}
