struct Vector3 {
    float x;
    float y;
    float z;
};

struct Pose_000E1240 {
    Vector3 position;
    Vector3 unknown_0c;
    Vector3 unknown_18;
};

struct Motion_000E1240 {
    short unknown_00;
    short frames;
};

struct MotionSet_000E1240 {
    char unknown_00[0x14];
    Motion_000E1240 *motions[1];
};

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

struct Owner_000E1240 {
    char unknown_00[0x70];
    float reach;
};

struct Object_000E0440 {
    char unknown_00[4];
    Owner_000E1240 *owner;
    char unknown_08[0x30];
    int side;
    char unknown_3c[0x3c];
    int index;
    char unknown_7c[0x40];
    MotionSet_000E1240 *set;

    int func_000E1240();
};

extern Object_000C1270 *data_00257CE4;

void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// Takes the last frame's position of the other side's motion (entry 1 - side + 2 * index of the set at +0xbc,
// func_0005E110); when it is nearer the position at +0x7c of data_00257CE4 than the owner's reach (+0x70),
// switches to that side and gives 1, else 0.
int Object_000E0440::func_000E1240()
{
    int other = 1 - side;
    Motion_000E1240 *motion = set->motions[other + index * 2];
    Pose_000E1240 pose;
    func_0005E110(motion, (float)motion->frames - 1.0f, 0, &pose);
    if (func_0014C530(&pose.position, &data_00257CE4->position) < owner->reach) {
        side = other;
        return 1;
    }
    return 0;
}
