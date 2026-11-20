struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00066980;

// The object in data_00257CE4: a point at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *clock;
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

// The owner type of the Object_000CC600 family; func_000C5B10 calls its callback at 0xe8.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

struct Sprite_000E45D0 {
    char unknown_00[0x18];
    float size;
};

struct Mesh_00017FD0 {
    Sprite_000E45D0 *sprite;
};

// The Node child func_000E45D0 builds (with a chain link at 0x44); these are its handlers by state (the member
// pointers at 0x258470, filled in by the dynamic initializer func_0018BF30).
struct Object_000E45D0 {
    char unknown_000[0x48];
    Vector3 position;
    char unknown_054[0x5c];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    int value_0bc;
    int value_0c0;
    char unknown_0c4[8];
    Vector3 target_0cc;
    int value_0d8;
    char unknown_0dc[0x68];
    int value_144;
    int value_148;
    char unknown_14c[0x10];
    Vector3 *targets;
    char unknown_160[0x94];
    Mesh_00017FD0 *mesh_1f4;
    char unknown_1f8[0x30];
    int value_228;

    void func_000E3E00();
};

// Entry 3 of the handlers at 0x258470: aims at the point 0xd8 of the list at 0x15c, sets the sprite size to 10 (twice),
// 0x144 = 15, 0x148 = 60 and 0xbc = 0, and hands the handle at 0x228 to the owner at 0xb0 (func_000C5B50).
void Object_000E45D0::func_000E3E00()
{
    target_0cc = targets[value_0d8];
    mesh_1f4->sprite->size = 10.0f;
    mesh_1f4->sprite->size = 10.0f;
    value_144 = 15;
    value_148 = 60;
    value_0bc = 0;
    owner->func_000C5B50(&value_228);
}
