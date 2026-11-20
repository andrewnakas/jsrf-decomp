struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000A4D80 {
    char unknown_000[0x1e4];
    Vector3 start;
    Vector3 value_1f0;
    char unknown_1fc[0x3c];
    int latched;

    void func_000A32B0(Vector3 *first, Vector3 *second);
    void func_000A5AC0();
};

// Entry 12 of the camera node's member-function table at 0x215534 (called by func_000A5070, its slot 1, when the mode
// at 0x208 changes): func_000A32B0 with the vectors at 0x1e4 and 0x1f0, and clears the latch at 0x238.
void Object_000A4D80::func_000A5AC0()
{
    func_000A32B0(&start, &value_1f0);
    latched = 0;
}
