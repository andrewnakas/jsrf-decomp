// A player (object 4 and on): how far it leans at +0xa70.
struct Object_000A1C50 {
    char unknown_0000[0xa70];
    float lean;

    void func_0007F8B0(int turn, float limit);
};

// Leans by about 0.1 a call towards the side of the turn when it is past 0x1c7 either way, up to the limit (at most
// 1); otherwise eases the lean back towards 0 by the same step.
void Object_000A1C50::func_0007F8B0(int turn, float limit)
{
    if (limit > 1.0f) {
        limit = 1.0f;
    }
    if (turn > 0x1c7) {
        lean += 0.10040161f;
        if (lean >= limit) {
            lean = limit;
        }
    } else if (turn < -0x1c7) {
        lean -= 0.10040161f;
        limit = -limit;
        if (lean <= limit) {
            lean = limit;
        }
    } else if (lean > 0.0f) {
        lean -= 0.10040161f;
        if (lean < 0.0f) {
            lean = 0.0f;
        }
    } else if (lean < 0.0f) {
        lean += 0.10040161f;
        if (lean > 0.0f) {
            lean = 0.0f;
        }
    } else {
        lean = 0.0f;
    }
}
