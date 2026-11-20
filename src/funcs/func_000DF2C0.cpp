struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

struct Object_000DF2C0 {
    char unknown_00[0x50];
    Vector3 position;

    void func_000DF2C0();
};

extern Object_000C1270 *data_00257CE4;

// Takes the position of the object in data_00257CE4.
void Object_000DF2C0::func_000DF2C0()
{
    position = data_00257CE4->position;
}
