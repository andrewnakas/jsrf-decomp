struct Object_00044AE0 {
    char unknown_000[0x48];
    int state;
    char unknown_04c[0x78];
    float unknown_c4;
    float unknown_c8;
    float unknown_cc;
    char unknown_0d0[0x10];
    int timer;

    int func_00044E80();
    int func_000464C0();
};

// Steps the hit state with func_00044E80 (1: clear, 2: hit at once, 3: clearing, 4: hit, with a timer at +0xe0) and
// returns it; resets it to 0 while +0xc4 is below +0xcc.
int Object_00044AE0::func_000464C0()
{
    if (!(unknown_c4 >= unknown_cc)) {
        state = 0;
        timer = 0;
        return 0;
    }
    int hit = func_00044E80();
    switch (state) {
    case 0:
        state = hit ? 2 : 1;
        break;
    case 1:
        if (hit) {
            state = 4;
            timer = 0x1e;
            return state;
        }
        break;
    case 2:
        if (!hit) {
            state = 3;
            timer = 6;
        }
        break;
    case 3:
        if (hit) {
            state = 4;
            timer = (6 - timer) * 5;
        }
        break;
    case 4:
        if (!hit) {
            timer = (0x1e - timer) / 5;
            state = 3;
        }
        break;
    }
    return state;
}
