struct Vector3 {
    float x;
    float y;
    float z;
};

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x60];
    float step;
    char unknown_64[0x1c];
    Vector3 home;
    char unknown_8c[0x18];
    unsigned int flags;
};

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    char unknown_0c[0xc];
    float time;
    char unknown_1c[0x24];
    int index;
    char unknown_44[4];
    int value_48;
    char unknown_4c[0x48];
    int value_94;

    float func_000CE770(Vector3 *point);
    int func_000CE2D0();
    void func_000CF850();
};

extern int data_00216664[3][5];

// A state handler: the time at 0x18 advances by the owner's step; unless 0x94 is 12, the owner loses flag 0x4000000
// and, with its flag 0x1000000, 0x94, 0x48 and the state come from the rows of data_00216664 by the index at 0x40,
// else state 2 and 0x94 = 1. Then func_000CE2D0.
void Object_000CE220::func_000CF850()
{
    time = owner->step + time;
    if (value_94 != 12) {
        owner->flags &= ~0x4000000;
        if (owner->flags & 0x1000000) {
            value_94 = data_00216664[2][index];
            value_48 = data_00216664[1][index];
            state = data_00216664[0][index];
        } else {
            state = 2;
            value_94 = 1;
        }
    }
    func_000CE2D0();
}
