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

    int func_000C5B10(int message, void *data);
};

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int timer;
    char unknown_14[0x80];
    int value_94;
    char unknown_98[4];
    int mode;

    int func_000CE2D0();
    void func_000CE8B0();
    void func_000CF690();
};

// A state handler: in mode 2 (0x9c), state 12, 0x94 = 8, the timer cleared, the owner told 0x41 for its position
// (func_000C5B10); then func_000CE2D0.
void Object_000CE220::func_000CF690()
{
    if (mode == 2) {
        state = 12;
        value_94 = 8;
        timer = 0;
        owner->func_000C5B10(0x41, &owner->position);
    }
    func_000CE2D0();
}
