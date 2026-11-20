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

    void func_000E3D80();
};

// Entry 1 of the handlers at 0x258470: aims at the point of data_00257CE4 lifted by 10, sets the sprite size to 15
// (twice), 0xc0 = 12 and 0xbc = 2, and sends message 12 with the position to the owner at 0xb0.
void Object_000E45D0::func_000E3D80()
{
    target_0cc = data_00257CE4->point;
    target_0cc.y += 10.0f;
    mesh_1f4->sprite->size = 15.0f;
    mesh_1f4->sprite->size = 15.0f;
    value_0c0 = 12;
    value_0bc = 2;
    owner->func_000C5B10(12, &position);
}
