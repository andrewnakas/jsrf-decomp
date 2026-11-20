struct Object_000A1C50 {
    char unknown_000[0x11c];
    int action;

    int func_00089B90();
    unsigned int func_0007F9B0(unsigned int range);
    void func_0008D1E0();
};

// Picks the player's action (+0x11c) for the kind func_00089B90 reports: 0x8a, 0x89, 0x8e, 0x8d, 0x8c or 0x8b for
// kinds 2 to 7, otherwise 0x8f or 0x90 at random (func_0007F9B0(100) below 50).
void Object_000A1C50::func_0008D1E0()
{
    switch (func_00089B90()) {
    case 2:
        action = 0x8a;
        break;
    case 3:
        action = 0x89;
        break;
    case 4:
        action = 0x8e;
        break;
    case 5:
        action = 0x8d;
        break;
    case 6:
        action = 0x8c;
        break;
    case 7:
        action = 0x8b;
        break;
    default:
        action = func_0007F9B0(100) < 50 ? 0x8f : 0x90;
        break;
    }
}
