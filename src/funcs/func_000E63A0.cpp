struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

struct Owner_000E5650 {
    char unknown_00[0x54];
    int heading;
    char unknown_58[4];
    float speed;
    float climb;
    char unknown_64[0x40];
    unsigned int flags;
};

struct Object_000E5650 {
    int unknown_00;
    Owner_000E5650 *owner;
    int state;
    char unknown_0c[4];
    int count;
    float x;
    float y;
    float z;
    char unknown_20[0x10];
    int value_30;
    int value_34;
    char unknown_38[4];
    int target_heading;
    float dir_x;
    char unknown_44[4];
    float dir_z;

    void func_000E63A0();
};

// A handler of the table at 0x218D90: moves the position at 0x14 by the owner's speed along (0x40, 0x48) and by its
// climb, turns the owner's heading toward 0x3c by 0x444; when 0x34 is 2: state 10, the count at 0x10 and the owner's
// speed cleared, and the owner gains the flags 0x1008000.
void Object_000E5650::func_000E63A0()
{
    Owner_000E5650 *o = owner;
    x += dir_x * o->speed;
    y += o->climb;
    z += dir_z * o->speed;
    owner->heading = data_00257CE8->func_000C1450(o->heading, target_heading, 0x444);
    if (value_34 == 2) {
        count = 0;
        state = 10;
        owner->speed = 0;
        owner->flags |= 0x1008000;
    }
}
