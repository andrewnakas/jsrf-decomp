struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);
float __fastcall func_0014CBA0(const Vector3 *a, const Vector3 *b);

// The model at 0x184: its target at 8.
struct Model_000CAD70 {
    char unknown_00[8];
    void *target;
};

// The motion set at 0x18c: an overlay motion at 0x24, a base motion at 0x3c and an override at 0x44 (-1 for none).
struct Motions_000CAD70 {
    char unknown_00[0x24];
    Motion_0005F060 *overlay;
    char unknown_28[0x14];
    Motion_0005F060 *base;
    char unknown_40[4];
    Motion_0005F060 *override;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    virtual void func_000CAD70();

    char unknown_04[0x44];
    Vector3 point_48;
    char unknown_54[0x3c];
    unsigned int flags;
    char unknown_94[0x48];
    Vector3 point_dc;
    char unknown_e8[0x9c];
    Model_000CAD70 *model;
    char unknown_188[4];
    Motions_000CAD70 *motions;
    Motion_0005F060 *motion;
    int value_194;
    Motion_0005F060 *overlay;
    int value_19c;
    char unknown_1a0[4];
    int value_1a4;
    float time;
    int value_1ac;
    float overlayTime;
    float blend;
    float fade;
    int moved;
    char unknown_1c0[4];
    int count;
};

// Slot 47: with flag 0x8000000 the motion set's overlay (if any) plays at half speed (func_0005E030 on 0x1b0), else
// none is kept at 0x198. On the first call (count 0x1c4 at 0) func_0005E7B0 sets the model up, the motion at 0x190
// becomes the override (or the base), the blend and fade (0x1b4, 0x1b8) start at 0.8 and the count steps. Later calls
// fade by 0.2 down to 0 (copied to the blend), or once faded play the motion at half speed (func_0005E030 on 0x1a8).
// 0x1bc is set when the points at 0x48 and 0xdc differ (func_0014CBA0).
void Object_000C7910::func_000CAD70()
{
    Motion_0005F060 *next;
    if ((flags & 0x8000000) && (next = motions->overlay) != 0) {
        overlay = next;
        func_0005E030(next, &overlayTime, 0.5f, 0);
    } else {
        overlay = 0;
    }
    if (count == 0) {
        func_0005E7B0(model->target, value_1a4, 0, value_19c, 0);
        if (motions->override == (Motion_0005F060 *)-1) {
            motion = motions->base;
        } else {
            motion = motions->override;
        }
        fade = 0.8f;
        blend = 0.8f;
        time = 0.0f;
        value_1ac = 0;
        value_194 = value_1a4;
        count++;
        return;
    }
    if (fade <= 0.0f) {
        value_194 = 0;
        func_0005E030(motion, &time, 0.5f, 0);
    } else {
        fade -= 0.2f;
        if (fade < 0.0f) {
            fade = 0.0f;
        }
        blend = fade;
    }
    if (func_0014CBA0(&point_48, &point_dc) != 0.0f) {
        moved = 1;
    }
}
