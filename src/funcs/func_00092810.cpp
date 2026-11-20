struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_001EB938.
struct Object_00014A80 {
    void func_00014CE0(int id, int index, void *position, Vector3 *up, void *target, int kind);
};

extern Object_00014A80 data_001EB938;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x13c];
    char target[0xb60];
    int id;
    char unknown_ca0[0xd0];
    char position[0x244];
    int value_fb4;

    void func_00092810();
};

// When 0xfb4 is 10: hands the player's id at 0xc9c, its points at 0xd70 and 0x13c and the up vector to
// func_00014CE0 of data_001EB938 (kind 2), and sets 0xfb4 to -1.
void Object_000A1C50::func_00092810()
{
    Vector3 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    if (value_fb4 == 10) {
        data_001EB938.func_00014CE0(id, -1, position, &up, target, 2);
        value_fb4 = -1;
    }
}
