int func_00119540(int group, int index, void *position);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc70];
    int sounds;
    char unknown_c74[0x30];
    char position[0xc];
    char unknown_cb0[0x1b0];
    int value_e60;
    char unknown_e64[0x2c0];
    unsigned int value_1124;
    char unknown_1128[4];
    int value_112c;
    int value_1130;
    unsigned int value_1134;

    void func_000A2200(int kind);
};

// Plays a sound of the group at 0xc70 at 0xca4: 26 while 0x1130 is set and 0x1134 at most 1; for kind 1, 7 or 8 by
// whether 0x112c is 1; otherwise, unless 0xe60 is set, 1 while 0x1124 counts, else 27, 28 or 1 for 0x112c 2, 6 or other.
void Object_000A1C50::func_000A2200(int kind)
{
    if (value_1130 && value_1134 <= 1) {
        func_00119540(sounds, 0x1a, position);
        return;
    }
    switch (kind) {
    case 1:
        switch (value_112c) {
        case 1:
            func_00119540(sounds, 7, position);
            break;
        default:
            func_00119540(sounds, 8, position);
            break;
        }
        return;
    }
    if (value_e60) {
        return;
    }
    if (value_1124 > 0) {
        func_00119540(sounds, 1, position);
    } else {
        switch (value_112c) {
        case 2:
            func_00119540(sounds, 0x1b, position);
            break;
        case 6:
            func_00119540(sounds, 0x1c, position);
            break;
        default:
            func_00119540(sounds, 1, position);
            break;
        }
    }
}
