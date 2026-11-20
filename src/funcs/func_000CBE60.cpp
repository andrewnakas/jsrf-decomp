struct Vector3 {
    float x;
    float y;
    float z;
};

// One box of data_00257CE0 (0x2c bytes).
struct Box_000CBE60 {
    char unknown_00[0x18];
    Vector3 center;
    char unknown_24[8];
};

struct Boxes_000CBE60 {
    int count;
    Box_000CBE60 *boxes;
};

struct Object_000BFF60 {
    Boxes_000CBE60 *data;

    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float value_5c;
    char unknown_60[4];
    int area;
    char unknown_68[0x40];
    Vector3 *target;

    int func_000C5A10();
};

struct Limits_000CC020 {
    char unknown_00[0x14];
    float rate;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
    char unknown_34[0x2c];
    Vector3 point;
};

// Slot 7: restarts the count; looks up the owner's box (func_000BFF80 of data_00257CE0 on its position, into
// 0x64). Outside every box: when the point at 0x60 is in one, the owner targets that box's center (0x18) in state 6,
// else the owner's 0x5c runs down by the rate at 0x14 of the object at 0x30, to 0. In a box: state 5, 4 or 3 as
// func_000C5A10 gives 0, 1 or anything else.
void Object_000CCE00::func_000CBE60()
{
    int box;
    count = 0;
    owner->area = data_00257CE0->func_000BFF80(&owner->position);
    if (owner->area < 0) {
        box = data_00257CE0->func_000BFF80(&point);
        if (box < 0) {
            if (owner->value_5c > 0.0f) {
                owner->value_5c -= limits->rate;
                if (owner->value_5c < 0.0f) {
                    owner->value_5c = 0.0f;
                }
            }
        } else {
            owner->target = &data_00257CE0->data->boxes[box].center;
            state = 6;
        }
    } else {
        int result = owner->func_000C5A10();
        if (!result) {
            state = 5;
        } else {
            state = result == 1 ? 4 : 3;
        }
    }
}
