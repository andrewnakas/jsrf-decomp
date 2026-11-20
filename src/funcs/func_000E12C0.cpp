extern "C" int memcmp(const void *first, const void *second, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Motion_000E1240;

// What func_0005E110 gives: a position and three angles.
struct Pose_000E1240 {
    Vector3 position;
    Angles_000C1300 angles;
    Vector3 unknown_18;
};

void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x50];
    Angles_000C1300 angles;
};

struct Limits_000CC020 {
    char unknown_00[0x1c];
    int step;
};

// The motions at 0xbc, two to a row.
struct Source_000E0440 {
    char unknown_00[0x14];
    Motion_000E1240 *motions[4][2];
};

struct Object_000E0440 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x28];
    Limits_000CC020 *limits;
    char unknown_034[4];
    int column;
    char unknown_03c[0x3c];
    int row;
    char unknown_07c[0x40];
    Source_000E0440 *source;

    int func_000E12C0();
};

// Turns each of the owner's angles by at most the step at 0x1c of the limits at 0x30 (func_000C1450) toward the
// first frame of the motion of the row at 0x78 and the column at 0x38 (func_0005E110); 1 once they all match.
// Called by slot 7 (func_000CD850).
int Object_000E0440::func_000E12C0()
{
    Pose_000E1240 pose;
    func_0005E110(source->motions[row][column], 0.0f, 0, &pose);
    owner->angles.x = data_00257CE8->func_000C1450(owner->angles.x, pose.angles.x, limits->step);
    owner->angles.y = data_00257CE8->func_000C1450(owner->angles.y, pose.angles.y, limits->step);
    owner->angles.z = data_00257CE8->func_000C1450(owner->angles.z, pose.angles.z, limits->step);
    int result = memcmp(&owner->angles, &pose.angles, sizeof(Angles_000C1300));
    return result == 0;
}
