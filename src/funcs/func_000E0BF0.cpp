struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1E60();
};

extern Object_00157F10 *data_00257CE8;

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BAA50();
void func_000C4B70(int kind);
void func_000C70A0(Node *owner, Vector3 *position, int kind);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int angles[3];
    int value_5c;
};

struct Object_000E0440 {
    char unknown_00[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int timer;

    void func_000E0BF0();
};

// Entry 6 of the handler table at 0x217DFC: sets up the matrix at the owner's position and angles, runs
// func_000C4B70(3), makes a kind-2 effect there (func_000C70A0) and kind 0x2f of object 0xe8 (func_000651E0), then
// goes to state 7 with the timer and the owner's 0x5c cleared and calls func_000C1E60 of data_00257CE8.
void Object_000E0440::func_000E0BF0()
{
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BAC50(owner->angles, 0);
    func_000C4B70(3);
    func_001BAA50();
    func_000C70A0(0, &owner->position, 2);
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x2f, &owner->position, 0);
    }
    state = 7;
    timer = 0;
    owner->value_5c = 0;
    data_00257CE8->func_000C1E60();
}
