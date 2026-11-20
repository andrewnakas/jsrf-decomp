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

struct Object_0006A960 {
    void func_0006BBA0(Vector3 *position, Light_00046920 *light);
};

extern Object_0006A960 data_0020C6C0;

void __fastcall func_001BA950(Matrix_001BA950 *matrix);

// Keeps the current matrix and has 0x20C6C0 place the top light at a position (func_0006BBA0); the top light becomes
// the current one.
void Object_00046670::func_00046670(Vector3 *position)
{
    func_001BA950(&matrix);
    data_0020C6C0.func_0006BBA0(position, &lights[count]);
    current = &lights[count];
    placed = &lights[count];
}
