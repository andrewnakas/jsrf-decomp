struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Motion_000E1240;

// What func_0005E110 gives: a position and three angles.
struct Pose_000E1240 {
    Vector3 position;
    int angles[3];
    Vector3 unknown_18;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int angles[3];
    char unknown_5c[0x48];
    unsigned int flags;
};

struct Object_000E0440 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0xb8];
    Motion_0005F060 *motion;
    float time;

    void func_000E0B30();
};

// Entry 3 of the handler table at 0x217DFC: plays the motion at 0xc4 at half speed; when it ends, puts the owner at
// the pose of its last frame (position and heading, the other two angles 0, func_0005E110), drops the motion,
// clears the owner's flag 0x1000000 and goes to state 4.
void Object_000E0440::func_000E0B30()
{
    if (func_0005E030(motion, &time, 0.5f, 1)) {
        Pose_000E1240 pose;
        func_0005E110((Motion_000E1240 *)motion, (float)motion->frames - 1.0f, 0, &pose);
        owner->position.x = pose.position.x;
        owner->position.y = pose.position.y;
        owner->position.z = pose.position.z;
        owner->angles[1] = pose.angles[1];
        owner->angles[2] = 0;
        owner->angles[0] = 0;
        motion = 0;
        owner->flags &= ~0x1000000;
        state = 4;
    }
}
