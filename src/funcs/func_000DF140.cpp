struct Owner_000DF140 {
    char unknown_00[0x68];
    int count;
};

struct Limits_000CC020 {
    char unknown_00[0x54];
    int limit;
};

// The owner at 4 and the limits at 0x30 sit where the class of func_000CC020 has them.
struct Object_000DF140 {
    char unknown_000[4];
    Owner_000DF140 *owner;
    int state;
    char unknown_00c[0x24];
    Limits_000CC020 *limits;
    char unknown_034[0x18c];
    int value_1c0;

    void func_000DE6C0();
    void func_000DF140();
};

// A handler of the member-function table at 0x217a50 (entry 3): counts the owner's count at 0x68 up; past the
// limit at 0x54, state 2 and 0 at 0x1c0; then func_000DE6C0.
void Object_000DF140::func_000DF140()
{
    owner->count++;
    if (owner->count > limits->limit) {
        state = 2;
        value_1c0 = 0;
    }
    func_000DE6C0();
}
