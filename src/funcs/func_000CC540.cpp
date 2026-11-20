struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

struct Object_000C1270 {
    char unknown_000[0xb8];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The class whose table is at 0x1CE320 (slots 9 and 10 call this).
struct Object_000CCE00 {
    int unknown_00;
    Object_000C5B50 *owner;
    char unknown_08[0x48];
    Vector3 position;

    int func_000CC540();
};

// Once the position at 0x50 is farther than 0.85 from the one at 0xb8 of data_00257CE4 (func_0014C800), gives the
// owner flag 0x400 and returns 1; else 0.
int Object_000CCE00::func_000CC540()
{
    if (func_0014C800(&data_00257CE4->position, &position) > 0.85f) {
        owner->flags |= 0x400;
        return 1;
    }
    return 0;
}
