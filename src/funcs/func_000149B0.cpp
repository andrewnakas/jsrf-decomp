struct Object_000149B0 {
    char unknown_00[0x4];
    int unknown_04;

    void func_000149B0();
};

void func_00086110(void *parent, int value);

// Sets the field at +0x4 and creates an object through func_00086110 (no parent given, value 0x50).
void Object_000149B0::func_000149B0()
{
    unknown_04 = 1;
    func_00086110(0, 0x50);
}
