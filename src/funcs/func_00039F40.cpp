struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0xd4];
    unsigned int bits_d8[8];
    unsigned int bits_f8[8];
    unsigned int bits_118[8];

    void func_00039F40();
};

void Object_00039BE0::func_00039F40()
{
    for (int i = 0; i < 8; i++) {
        bits_118[i] = 0;
    }
}
