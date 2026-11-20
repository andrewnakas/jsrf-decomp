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
    char unknown_14[0x80];
    int value_94;
    char unknown_98[4];
    int mode;

    void func_000CE2D0();
    void func_000CE8B0();
    void func_000CF940();
};

// A state handler: func_000CE8B0; then in mode 2 (0x9c), unless the owner has flag 0x80, state 24, 0x94 = 18 and
// the owner's 0x5c cleared.
void Object_000CE220::func_000CF940()
{
    func_000CE8B0();
    if (mode == 2 && !(owner->flags & 0x80)) {
        state = 24;
        value_94 = 18;
        owner->value_5c = 0.0f;
    }
}
