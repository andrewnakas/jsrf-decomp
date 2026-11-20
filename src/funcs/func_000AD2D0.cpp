// The class whose table is at 0x1CD7B0 (only the fields this method uses).
struct Object_000ACFB0 {
    char unknown_000[0x84];
    int unknown_084[9];
    char unknown_0a8[0x40];
    int unknown_0e8;
    char unknown_0ec[0xf4];
    float target[3];
    float unknown_1ec[3];
    float scale[3];
    int angle[3];
    float unknown_210[3];

    void func_000AD2D0();
};

// Clears the target at 0x1e0, the vectors at 0x1ec and 0x210, the angles at 0x204, the nine values at 0x84 and
// the value at 0xe8, and sets the scale at 0x1f8 to 1.
void Object_000ACFB0::func_000AD2D0()
{
    for (int i = 0; i < 3; i++) {
        target[i] = 0.0f;
        unknown_1ec[i] = 0.0f;
        scale[i] = 1.0f;
        angle[i] = 0;
        unknown_210[i] = 0.0f;
    }
    unknown_084[0] = 0;
    unknown_084[1] = 0;
    unknown_084[2] = 0;
    unknown_084[3] = 0;
    unknown_084[4] = 0;
    unknown_084[5] = 0;
    unknown_084[6] = 0;
    unknown_084[7] = 0;
    unknown_084[8] = 0;
    unknown_0e8 = 0;
}
