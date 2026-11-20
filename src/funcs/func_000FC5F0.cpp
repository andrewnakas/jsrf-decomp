// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself.
struct Object_000FBFD0 {
    char unknown_00[0x54];
    int value_54;
    char unknown_58[8];
    void *sprite_60;
    char unknown_64[0x18];
    void *sprite_7c;
    int unknown_80;
    void *sprite_84;

    void func_000FC5F0();
};

void *func_00025700(unsigned int index, int first, int second, int third);

// Entry 1 of that table: loads the three sprites (the first chosen by the value at 0x54).
void Object_000FBFD0::func_000FC5F0()
{
    sprite_60 = func_00025700(0xa, 0, 1, value_54 + 0x3c);
    sprite_7c = func_00025700(0xa, 0, 1, 0x62);
    sprite_84 = func_00025700(0xa, 0, 2, 9);
}
