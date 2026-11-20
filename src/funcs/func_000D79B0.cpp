struct Object_000C5B50 {
    int func_000C59A0();
};

// Shared by the classes of 0xD6350 and 0xE9380 (both called from their handlers).
struct Object_000CD1E0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;

    void func_000E90A0();
    int func_000D7540(int flags);
};

struct Object_000D6350 : Object_000CD1E0 {
    void func_000D79B0();
};

// A handler of the table at 0x21718C (entry 3): func_000E90A0; state 2 unless func_000D7540(1) and the owner's
// func_000C59A0 both succeed.
void Object_000D6350::func_000D79B0()
{
    func_000E90A0();
    if (!func_000D7540(1) || !owner->func_000C59A0()) {
        state = 2;
    }
}
