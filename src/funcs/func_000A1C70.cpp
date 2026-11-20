struct Vector3 {
    float x;
    float y;
    float z;
};

int func_00119540(int group, int index, void *position);

struct Object_000A1C50 {
    char unknown_000[0xc70];
    int group_c70;
    int group_c74;
    char unknown_c78[0x10];
    int handle_c88;
    char unknown_c8c[0x18];
    Vector3 position;

    void func_000A1C70();
};

// While the handle at 0xc88 is unset (negative), takes it from func_00119540: entry 23 of the object's
// group at 0xc74, at the object's position.
void Object_000A1C50::func_000A1C70()
{
    if (handle_c88 < 0) {
        handle_c88 = func_00119540(group_c74, 23, &position);
    }
}
