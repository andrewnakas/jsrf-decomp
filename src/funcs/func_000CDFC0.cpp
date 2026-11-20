struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int argument);
};

extern Object_00046670 data_001F93C8;

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    int value_5c;
    char unknown_60[0x8];
    int value_68;
    char unknown_6c[0x38];
    unsigned int flags;
};

// The objects whose state handlers fill the table at 0x2165F0 to 0x216660.
struct Object_000CE220 {
    int unknown_00;
    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x18];
    float value_2c;
    char unknown_30[0x14];
    int value_44;
    char unknown_48[0xd8];
    int value_120;
    char unknown_124[0x10];
    int handle;

    void func_000CDFC0();
};

// A state handler (the entry at 0x2165F0): clears the owner's fields at 0x5c and 0x68 and its flags, then the
// count, 0x120 and 0x44, unsets the handle at 0x134, state 1, and keeps func_000466C0 of 0x1F93C8 for the owner's
// position at 0x2c.
void Object_000CE220::func_000CDFC0()
{
    owner->value_5c = 0;
    owner->value_68 = 0;
    owner->flags = 0;
    count = 0;
    state = 1;
    value_120 = 0;
    value_44 = 0;
    handle = -1;
    value_2c = data_001F93C8.func_000466C0(&owner->position, -1);
}
