struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_0004[0x2974];
    int unknown_2978;
    int unknown_297c;

    void func_0003A4C0(int *first, int *second);
};

void Object_00039BE0::func_0003A4C0(int *first, int *second)
{
    *first = unknown_2978;
    *second = unknown_297c;
}
