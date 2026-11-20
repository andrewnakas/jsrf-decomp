/* sym: ?func_000CD210@Object_000E0440@@UAEXXZ = 0x000E0A20 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Pose_000E1240 {
    Vector3 position;
    int rotation[3];
    Vector3 unknown_18;
};

struct Motion_000E1240 {
    short unknown_00;
    short frames;
};

void func_0005E110(Motion_000E1240 *motion, float time, int flags, Pose_000E1240 *out);
unsigned int func_0014C690(float value);

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int id);
};

extern Object_00046670 data_001F93C8;

// The object a behaviour serves.
struct Owner_000E0A20 {
    char unknown_00[0x44];
    Vector3 position;
    int rotation[3];
    char unknown_5c[0x48];
    unsigned int flags;
};

// The path the object runs on (0x70): its end point, and a value at 0xc.
struct Path_000E0A20 {
    Vector3 end;
    float value;
};

struct Entry_000E0A20 {
    Motion_000E1240 *motion;
    int unknown_04;
};

struct MotionSet_000E0A20 {
    char unknown_00[0x14];
    Entry_000E0A20 entries[1];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Owner_000E0A20 *owner;
    int state;
    char unknown_0c[0x20];
    float height;
    char unknown_30[8];
    int value_38;
    char unknown_3c[0x28];
    int value_64;
    int unknown_68;
};

// The class whose table is at 0x1CE804; slot 6 is empty (folded with Node's).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    unsigned int steps;
    Path_000E0A20 *path;
    char unknown_074[4];
    unsigned int index;
    char unknown_07c[0x18];
    int value_094;
    int value_098;
    int value_09c;
    char unknown_0a0[0x14];
    int value_0b4;
    char unknown_0b8[4];
    MotionSet_000E0A20 *set;
    char unknown_0c0[4];
    int value_0c4;
    int value_0c8;
    char unknown_0cc[0x14];
    float value_0e0;
};

// Slot 5: clears the owner's flags 0x101, takes the motion index from the path's value at 0xc (0x78); with at most
// one step (0x6c) state 5 at the path's end point, else state 4 at the last frame of the indexed motion's pose (its
// position and turn, the other turns cleared); resets the motion state and puts the height at 0x2c from
// data_001F93C8 under the owner's position.
void Object_000E0440::func_000CD210()
{
    owner->flags &= ~0x101;
    index = func_0014C690(path->value);
    value_38 = 0;
    if (steps <= 1) {
        state = 5;
        owner->position = path->end;
    } else {
        state = 4;
        Motion_000E1240 *motion = set->entries[index].motion;
        Pose_000E1240 pose;
        func_0005E110(motion, (float)motion->frames - 1.0f, 0, &pose);
        owner->position.x = pose.position.x;
        owner->position.y = pose.position.y;
        owner->position.z = pose.position.z;
        owner->rotation[1] = pose.rotation[1];
        owner->rotation[2] = 0;
        owner->rotation[0] = 0;
    }
    value_64 = 0;
    value_098 = 0;
    value_09c = 0;
    value_094 = 0;
    value_0e0 = -1.0f;
    value_0b4 = 0;
    value_0c4 = 0;
    value_0c8 = 0;
    height = data_001F93C8.func_000466C0(&owner->position, -1);
}
