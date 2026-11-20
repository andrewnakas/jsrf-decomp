// The child of Node whose table is at 0x1CE1C8 (only the fields this method uses).
struct Object_000C7910 {
    char unknown_000[0x60];
    float scale;
    float rate;
    char unknown_068[0x54];
    int state;
    char unknown_0c0[0xfc];
    int value_1bc;

    void func_000C83A0();
};

// Below 1.39 the scale at 0x60 grows by half and the rate is 0.463 with state 9 and 8 at 0x1bc; else it doubles,
// rate 0.926, state 10 and 9.
void Object_000C7910::func_000C83A0()
{
    if (scale < 1.3888888f) {
        scale *= 1.5f;
        rate = 0.46296296f;
        state = 9;
        value_1bc = 8;
    } else {
        scale += scale;
        rate = 0.9259259f;
        state = 10;
        value_1bc = 9;
    }
}
