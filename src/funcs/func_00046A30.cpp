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

struct Matrix_001BA950 {
    float m[4][4];
};

// The light stack at 0x1F93C8: five lights, the count at +0x230, a matrix and the current light.
struct Object_00046670 {
    Light_00046920 lights[5];
    int count;
    Matrix_001BA950 matrix;
    Light_00046920 *current;
    Light_00046920 *placed;

    void func_00046670(Vector3 *position);
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

// Pops the light stack and applies the light below (func_00046940 with its first word).
void Object_00046670::func_00046A30()
{
    count--;
    current = &lights[count];
    func_00046940(current->unknown_00);
}
