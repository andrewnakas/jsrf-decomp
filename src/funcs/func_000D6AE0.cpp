struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1E60.
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;
// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    char unknown_60[0x44];
    unsigned int flags;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
};

// The behaviour func_000D6350 builds; this is an entry of its handler table at 0x21718C (the pointer at 0x74), and
// the same code serves Object_000E7F50's table at 0x219144.
struct Object_000D6350 {
    void *vtable;
    Object_000C5B50 *desc;
    int state;
    char unknown_0c[4];
    int count;
    char unknown_14[0x2b8];
    int handle_2cc;

    void func_000D6AE0();
};

// Entry 6: object 0xE8, if there is one, gets func_000651E0 kind 0x36 at the position of the object served; then
// state 7, the count and that object's speed cleared, the handle at 0x2cc handed to it and message 0x20 with its
// position; then func_000C1E60 on data_00257CE8.
void Object_000D6350::func_000D6AE0()
{
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        node->func_000651E0(0x36, &desc->position, 0);
    }
    state = 7;
    count = 0;
    desc->speed = 0.0f;
    desc->func_000C5B50(&handle_2cc);
    desc->func_000C5B10(0x20, &desc->position);
    data_00257CE8->func_000C1E60();
}
