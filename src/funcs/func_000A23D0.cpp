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

    void func_000A23D0();
};

// Asks func_00119540 for entry 17 of the object's group at 0xc70, at the object's position.
void Object_000A1C50::func_000A23D0()
{
    func_00119540(group_c70, 17, &position);
}
