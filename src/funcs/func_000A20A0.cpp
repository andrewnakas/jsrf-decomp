int func_00119540(int group, int index, void *position);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc74];
    int group;
    char unknown_c78[0x2c];
    char position[0xc];

    unsigned int func_0007F9B0(unsigned int range);
    void func_000A20A0();
};

// Plays sound 19 or 20 of the player's group (0xc74) at 0xca4, by an even draw of func_0007F9B0 (below 50 of
// 100: 19).
void Object_000A1C50::func_000A20A0()
{
    if (func_0007F9B0(100) < 50) {
        func_00119540(group, 19, position);
    } else {
        func_00119540(group, 20, position);
    }
}
