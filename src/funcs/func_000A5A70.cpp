struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A4BD0 {
    char unknown_000[0x158];
    Vector3 position;
    int value_164;
    char unknown_168[0x7c];
    Vector3 start;
    char unknown_1f0[0x38];
    int value_228;
    char unknown_22c[8];
    int value_234;
    int latched;

    void func_000A5A70();
};

// Copies the position at 0x1e4 to 0x158 and clears 0x164; the first time only, also copies the field at 0x228 to
// 0x234 and sets the latch at 0x238 (like func_000A4BD0).
void Object_000A4BD0::func_000A5A70()
{
    position = start;
    value_164 = 0;
    if (!latched) {
        value_234 = value_228;
        latched = 1;
    }
}
