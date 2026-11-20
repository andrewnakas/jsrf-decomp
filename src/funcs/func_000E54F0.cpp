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

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);

// The object a behaviour serves (at 0x4).
struct Owner_000E54F0 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float value_5c;
    float value_60;
    char unknown_64[0x1c];
    Vector3 start;
    char unknown_8c[0x18];
    unsigned int flags;
};

struct Object_000E6590 {
    char unknown_00[4];
    Owner_000E54F0 *owner;
    int state;
    char unknown_0c[4];
    int timer;
    Vector3 position;
    char unknown_20[0xc];
    float height;
    char unknown_30[8];
    int heading;

    void func_000E54F0();
};

// Entry 0 of the handler table at 0x218D90: clears the owner's flags, puts this object and the owner at the owner's
// start point (0x80) at rest, state 1; turns the owner to face the way its angles point (func_000C1F20 on
// (0, 0, -1) turned by them), levels it, keeps its heading at 0x38 and the ground height at 0x2c (func_000466C0).
void Object_000E6590::func_000E54F0()
{
    owner->flags = 0;
    position = owner->start;
    owner->position = owner->start;
    owner->value_60 = 0.0f;
    owner->value_5c = 0.0f;
    timer = 0;
    state = 1;
    Vector3 ahead;
    ahead.x = 0.0f;
    ahead.y = 0.0f;
    ahead.z = -1.0f;
    func_001BAA00();
    func_001BAC50(&owner->angles.x, 0);
    func_001BAC00(&ahead, &ahead);
    func_001BAA50();
    data_00257CE8->func_000C1F20(&owner->angles, &ahead, 0x8000);
    owner->angles.z = 0;
    owner->angles.x = 0;
    heading = owner->angles.y;
    height = data_001F93C8.func_000466C0(&owner->position, -1);
}
