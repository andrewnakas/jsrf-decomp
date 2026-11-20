/* sym: ?func_000CD210@Object_000DB8F0@@UAEXXZ = 0x000DBF00 */
// The owner at 0x4.
struct Owner_000DBF00 {
    char unknown_00[0x50];
    int value_50;
    char unknown_54[4];
    int value_58;
    char unknown_5c[0x48];
    unsigned int flags;
};

struct Object_000CD1E0 {
    virtual void func_000CD210();

    Owner_000DBF00 *owner;
    int state;
};

// The child of Object_000CD1E0 whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 : Object_000CD1E0 {
    virtual void func_000CD210();

    char unknown_0c[0xa4];
    int value_b0;
};

// Overrides slot 5: runs Object_000CD1E0's, then clears 0xb0, sets state 3, clears the owner's fields at 0x58
// and 0x50 and its flags 0x101.
void Object_000DB8F0::func_000CD210()
{
    Object_000CD1E0::func_000CD210();
    value_b0 = 0;
    state = 3;
    owner->value_58 = 0;
    owner->value_50 = 0;
    owner->flags &= ~0x101;
}
