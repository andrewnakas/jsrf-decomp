struct Object_000C5B50 {
    int func_000C59A0();
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1630.
struct Object_00157F10 {
    int func_000C1630();
};

extern Object_00157F10 *data_00257CE8;

// Shared by the classes of 0xD6350 and 0xE9380 (both called from their handlers).
struct Object_000CD1E0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;

    void func_000E90A0();
    int func_000D7540(int flags);
};

struct Object_000E7F50 : Object_000CD1E0 {
    void func_000E9380();
};

// A handler of the table at 0x219144 (entry 3): func_000E90A0; state 2 unless func_000D7540(1), the owner's
// func_000C59A0 and func_000C1630 on data_00257CE8 all succeed.
void Object_000E7F50::func_000E9380()
{
    func_000E90A0();
    if (!func_000D7540(1) || !owner->func_000C59A0() || !data_00257CE8->func_000C1630()) {
        state = 2;
    }
}
