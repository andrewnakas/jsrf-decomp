struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Set_000D27F0 {
    Motion_0005F060 *motions[64];
};

struct Owner_000D52A0 {
    char unknown_00[0x54];
    int value_54;
};

struct Object_000D27F0 {
    char unknown_000[0x4];
    Owner_000D52A0 *owner;
    char unknown_008[0x44];
    int value_4c;
    char unknown_050[0x38];
    int mode;
    char unknown_08c[0xe74];
    Set_000D27F0 *set;
    char unknown_f04[0x4];
    Motion_0005F060 *blend;
    char unknown_f0c[0x14];
    float blend_time;
    char unknown_f24[0x4];
    float weight;

    void func_000D52A0();
};

// In mode 0 (0x88): raises the blend weight at 0xf28 by 0.1 (to at most 1) while the owner's 0x54 differs from 0x4c
// and lowers it by 0.1 (to no less than 0) once they agree; with any weight left blends motion 54 in (0xf08, played
// once at half speed from 0xf20), and without clears the blend motion and its time.
void Object_000D27F0::func_000D52A0()
{
    if (mode == 0) {
        if (owner->value_54 != value_4c) {
            weight += 0.1f;
            if (weight > 1.0f) {
                weight = 1.0f;
            }
        } else {
            weight -= 0.1f;
            if (weight < 0.0f) {
                weight = 0.0f;
            }
        }
        if (weight > 0.0f) {
            blend = set->motions[54];
            func_0005E030(blend, &blend_time, 0.5f, 0);
        } else {
            blend = 0;
            blend_time = 0.0f;
        }
    }
}
