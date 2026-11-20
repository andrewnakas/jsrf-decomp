struct Object_00081860 {
    virtual ~Object_00081860();

    char unknown_004[0xe4c];
    int unknown_e50;
    char unknown_e54[0x18];
    int unknown_e6c;

    void func_0007FF90();
};

// Sets the field at +0xe50 to 0x1b (the value func_00082770 and func_00082790 test) and clears the one at +0xe6c.
void Object_00081860::func_0007FF90()
{
    unknown_e50 = 0x1b;
    unknown_e6c = 0;
}
