struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0x10];
    unsigned int flags;

    int func_00039D10(unsigned int index);
};

int Object_00039BE0::func_00039D10(unsigned int index)
{
    if (index < 0x20 && (flags & (1 << index))) {
        return 1;
    }
    return 0;
}
