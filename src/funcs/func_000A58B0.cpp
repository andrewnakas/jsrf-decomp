struct Object_000A4D80 {
    char unknown_000[0xf4];
    int value_f4;
    char unknown_0f8[0x140];
    int value_238;

    void func_000A58B0();
};

// Entries 0 and 1 of the camera node's member-function table at 0x215534, which func_000A5070 (slot 1 of
// Object_000A4D80) calls on itself when the mode at 0x208 changes: clears 0xf4 and 0x238.
void Object_000A4D80::func_000A58B0()
{
    value_f4 = 0;
    value_238 = 0;
}
