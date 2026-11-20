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

extern Light_00046920 data_001F9358;

struct Object_00046670 {
    void func_00046920(Light_00046920 *light);
};

// Copies the default light (the 0x70-byte block at 0x1F9358) out.
void Object_00046670::func_00046920(Light_00046920 *light)
{
    *light = data_001F9358;
}
