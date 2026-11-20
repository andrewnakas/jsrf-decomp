struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0x10];
    unsigned int flags;

    void func_00039CF0(unsigned int index);
};

void Object_00039BE0::func_00039CF0(unsigned int index)
{
    if (index < 0x20) {
        flags &= ~(1 << index);
    }
}
