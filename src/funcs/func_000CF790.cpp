struct Vector3 {
    float x;
    float y;
    float z;
};

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;

    int func_000C5B10(int first, int second);
};

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x2c];
    int index;
    char unknown_44[0x50];
    int value_94;
    char unknown_98[4];
    int mode;

    void func_000CE2D0();
    void func_000CE8B0();
    void func_000CF790();
};

// A state handler: once the timer at 0x10 passes 120, the index at 0x40 and the timer clear; with the owner's flag
// 0x1000000, state 3 and 0x94 = 0, else state 2 and 0x94 = 1. Then func_000CE2D0.
void Object_000CE220::func_000CF790()
{
    if (++timer > 120) {
        index = 0;
        timer = 0;
        if (owner->flags & 0x1000000) {
            state = 3;
            value_94 = 0;
        } else {
            state = 2;
            value_94 = 1;
        }
    }
    func_000CE2D0();
}
