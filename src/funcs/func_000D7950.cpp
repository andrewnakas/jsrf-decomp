/* sym: ?func_000CD850@Object_000D6350@@UAEXXZ = 0x000D7950 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (the owner at 0x4): its position at 0x44, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x54];
    unsigned int flags;

    int func_000C59A0();
    void func_000C5B40(int handle, void *data);
    int func_000C5B10(int message, void *data);
    int func_000C5B70(int handle);
};

// The limits a behaviour reads (at 0x30): a value at 0x14.
struct Limits_000D6350 {
    char unknown_00[0x14];
    int value_14;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DEB0(int key, int value);
};

extern Object_0006DB80 data_00251F78;

// The base of the moving behaviours (table 0x1CE3E0).
struct Object_000CD1E0 {
    virtual void func_000CD800();
    virtual void func_000CD850();

    void func_000CD5C0();
    int func_000D7540(int value);

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[4];
    int value_10;
    char unknown_14[0x1c];
    Limits_000D6350 *limits;
    char unknown_34[0x38];
    unsigned int count;
    char unknown_70[0x60];
    char point[0x10];
};

// The class whose table is at 0x1CE5F0 (constructor func_000D6350); slots 6 and 7 are shared with the class of
// 0x1CEE44 (Object_000E7F50).
struct Object_000D6350 : Object_000CD1E0 {
    virtual void func_000CD800();
    virtual void func_000CD850();

    char unknown_0e0[0x1d8];
    int key;
    char unknown_2bc[0x10];
    int handle;
};

// Slot 7: runs Object_000CD1E0's slot, goes to state 3 when the owner allows it (func_000C59A0) and func_000D7540
// agrees, then moves the owner's handle at 0x2cc to its position (func_000C5B40) or, when the owner no longer has it
// (func_000C5B70), takes a new one (message 0x1e).
void Object_000D6350::func_000CD850()
{
    Object_000CD1E0::func_000CD850();
    if (owner->func_000C59A0() && func_000D7540(0)) {
        state = 3;
    }
    if (owner->func_000C5B70(handle)) {
        owner->func_000C5B40(handle, &owner->position);
    } else {
        handle = owner->func_000C5B10(0x1e, &owner->position);
    }
}
