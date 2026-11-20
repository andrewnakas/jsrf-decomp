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

    void func_000466D0();
};

// Pushes the current light: copies it into the next slot and counts it.
void Object_00046670::func_000466D0()
{
    lights[count + 1] = lights[count];
    count++;
}
