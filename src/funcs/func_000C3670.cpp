struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

struct Data_000C2700 {
    unsigned char type;
    unsigned char mode;
    char unknown_02;
    unsigned char count;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470).
struct Object_000C2420 {
    virtual void func_000C2630();

    char unknown_04[0xc];
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    char unknown_2c[0xc];
    unsigned int index;
    int step;
    char unknown_40[0x38];
    Data_000C2700 *data;

    int func_000C2DE0();
    void func_000C3670();
};

// On arrival (func_000C2DE0) moves the index at 0x38 one step on through the data's count of points, turning
// back at either end; then moves the point at 0x10 by the speed at 0x28 along the angles at 0x1c
// (func_000C1300).
void Object_000C2420::func_000C3670()
{
    Vector3 direction;
    if (func_000C2DE0()) {
        if (index >= data->count - 1u)
            step = -1;
        else if (index <= 0)
            step = 1;
        index += step;
    }
    data_00257CE8->func_000C1300(&angles, &direction);
    position.x += direction.x * speed;
    position.y += direction.y * speed;
    position.z += direction.z * speed;
}
