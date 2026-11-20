struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00066980 {
    float func_00066950();
};

struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *value_78;
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

struct Set_000DCBC0 {
    Motion_0005F060 *motions[64];
};

struct Object_000DCBC0 {
    char unknown_000[0x190];
    Set_000DCBC0 *set;
    Motion_0005F060 *motion;
    char unknown_198[0x14];
    float time;
    char unknown_1b0[0x4];
    float time_1b4;
    char unknown_1b8[0x8];
    int next;
    char unknown_1c4[0x4];
    int phase;

    void func_000DF800();
};

// A handler of the table at 0x217A20: starts motion 19 at time 0 (phase 1), then plays it at half speed, looping;
// each time it wraps, gives 8 at 0x1c0 when func_00066950 of the object at 0x78 of data_00257CE4 is below 0.1, and
// otherwise starts the motion over.
void Object_000DCBC0::func_000DF800()
{
    if (phase == 0) {
        motion = set->motions[19];
        time = 0.0f;
        time_1b4 = 0.0f;
        phase = 1;
        return;
    }
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        if (data_00257CE4->value_78->func_00066950() < 0.1f) {
            next = 8;
        } else {
            time = 0.0f;
        }
    }
}
