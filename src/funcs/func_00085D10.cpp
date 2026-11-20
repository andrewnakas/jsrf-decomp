void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

struct Object_00086060 {
    char unknown_000[0x48];
    float start[3];
    char unknown_054[0xc];
    int angle;
    char unknown_064[0x38];
    unsigned int flags;

    void func_00085640();
    void func_00085D10();
};

// Handler 0 of the tables at 0x20D9DC and 0x20D9F0: with flag 1, runs func_00085640 under the start point and turns
// the angle at +0x60 back towards 0 by at most 0x222.
void Object_00086060::func_00085D10()
{
    if (flags & 1) {
        func_001BA9C0();
        func_001BAAA0(start);
        func_00085640();
        func_001BAA50();
        if (angle) {
            int value = angle;
            int step;
            if ((short)value > 0x222) {
                step = 0x222;
            } else if ((short)value < -0x222) {
                step = -0x222;
            } else {
                step = value;
            }
            angle = value - step;
        }
    }
}
