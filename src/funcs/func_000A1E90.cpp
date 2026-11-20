int func_00119540(int sound, int kind, void *position);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc74];
    int sound;
    char unknown_c78[0x2c];
    char position[0xc];

    unsigned int func_0007F9B0(unsigned int range);
    void func_000A1E90();
};

// Plays one of five voices (kinds 1 to 5 of its sound at 0xc74, at 0xca4; func_00119540) with chances 20 each
// (func_0007F9B0(100)).
void Object_000A1C50::func_000A1E90()
{
    unsigned int roll = func_0007F9B0(100);
    if (roll < 20) {
        func_00119540(sound, 1, position);
    } else if (roll < 40) {
        func_00119540(sound, 2, position);
    } else if (roll < 60) {
        func_00119540(sound, 3, position);
    } else if (roll < 80) {
        func_00119540(sound, 4, position);
    } else {
        func_00119540(sound, 5, position);
    }
}
