struct Object_00074260 {
    char unknown_00[0xb4];
    unsigned int flags;

    void func_00074260();
    void func_000743C0();
};

void Object_00074260::func_000743C0()
{
    flags |= 0x40000000;
    func_00074260();
}
