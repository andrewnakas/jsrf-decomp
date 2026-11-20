struct Object_0011B2F0 {
    char unknown_00[0x44];
    int state;

    void func_0011B2F0();
};

struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
void func_00024620(unsigned int color, float step);

// While game value 0x1ad is 0, calls func_00024620 with black and a step of 1/60 and goes to state 6.
void Object_0011B2F0::func_0011B2F0()
{
    if (data_0022FCE0->func_000127E0(0x1ad) == 0) {
        func_00024620(0xff000000, 1.0f / 60.0f);
        state = 6;
    }
}
