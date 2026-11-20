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
    char unknown_c78[0x2c];
    Vector3 position;

    unsigned int func_0007F9B0(unsigned int range);
    void func_000A1E20();
};

// Picks entry 1, 2 or 3 of the object's group at 0xc74 by a third each (func_0007F9B0(100) below 33, 66, 100) and
// asks func_00119540 for it at the object's position.
void Object_000A1C50::func_000A1E20()
{
    unsigned int roll = func_0007F9B0(100);
    if (roll < 33) {
        func_00119540(group_c74, 1, &position);
    } else if (roll < 66) {
        func_00119540(group_c74, 2, &position);
    } else {
        func_00119540(group_c74, 3, &position);
    }
}
