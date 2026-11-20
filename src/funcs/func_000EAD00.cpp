struct Object_000EAB40 {
    char unknown_000[8];
    int state;
    char unknown_00c[0x138];
    int busy;

    int func_000EAB40();
    void func_000EAD00();
};

void Object_000EAB40::func_000EAD00()
{
    if (!busy) {
        state = 1;
        func_000EAB40();
    }
}
