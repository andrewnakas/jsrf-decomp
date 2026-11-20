struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0xa0];
    int kind;
    unsigned int flags;

    int func_000C59A0();
};

// The owner's tests, by its kind at 0xa0 (func_000C5B90, func_000C5DB0, func_000C62B0, func_000C6460,
// func_000C5E50).
extern int (Object_000C5B50::*data_00216214[])(Vector3 *point);

// True once when flag 0x800 is set (and clears it); otherwise the test of the owner's kind on the point at 0x7c
// of data_00257CE4.
int Object_000C5B50::func_000C59A0()
{
    if (flags & 0x800) {
        flags &= ~0x800;
        return 1;
    }
    return (this->*data_00216214[kind])(&data_00257CE4->unknown_7c) != 0;
}
