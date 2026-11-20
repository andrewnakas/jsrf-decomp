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

    void func_000A24B0();
};

// Asks func_00119540 for entry 4 of group 8, at the object's position.
void Object_000A1C50::func_000A24B0()
{
    func_00119540(8, 4, &position);
}
