struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00066980;

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1E60.
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

void func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The chain link (table 0x1CE1B8).
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Model_000E45D0 {
    char unknown_00[8];
    void *target;
};

struct Holder_000E45D0 {
    Model_000E45D0 *model;
};

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
struct Object_000E45D0 : Node, Object_000C60C0 {
    Vector3 position;
    char unknown_054[0x3c];
    unsigned int flags_090;
    char unknown_094[0x1c];
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
    char unknown_160[4];
    Holder_000E45D0 *holder;
    char unknown_168[4];
    int handle_16c;
    int handle_170;
    char unknown_174[4];
    int value_178;
    char unknown_17c[0x78];
    Mesh_00017FD0 *mesh_1f4;
    char unknown_1f8[0x2c];
    int value_224;

    void func_000E3E80();
};

// Entry 4 of the handlers at 0x258470: gains the flag 0x2000 at 0x90, state 5 at 0xbc, runs the link's slot 1, clears
// 0x178, restarts the handles at 0x170 and 0x16c on the holder's target (func_0005E7B0), hands the handle at 0x224 to
// the owner at 0xb0 and sends it message 0x11 with the position; then func_000C1E60 on data_00257CE8.
void Object_000E45D0::func_000E3E80()
{
    flags_090 |= 0x2000;
    value_0bc = 5;
    func_000C60C0();
    value_178 = 0;
    func_0005E7B0(holder->model->target, handle_170, 0, handle_16c, 0);
    owner->func_000C5B50(&value_224);
    owner->func_000C5B10(0x11, &position);
    data_00257CE8->func_000C1E60();
}
