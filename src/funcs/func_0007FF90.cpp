struct Object_000A1C50 {
    virtual ~Object_000A1C50();

    char unknown_004[0xe4c];
    int unknown_e50;
    char unknown_e54[0x18];
    int unknown_e6c;

    void func_0007FF90();
};

// Sets the field at +0xe50 to 0x1b (the value slots 3 and 6 of the table at 0x1CCFF8 test) and clears the one at +0xe6c.
void Object_000A1C50::func_0007FF90()
{
    unknown_e50 = 0x1b;
    unknown_e6c = 0;
}
