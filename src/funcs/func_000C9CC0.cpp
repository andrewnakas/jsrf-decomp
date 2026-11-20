struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_00157F10 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

struct Info_000C7910 {
    char unknown_00[0x3c];
    float gravity;
    float fallLimit;
};

struct Speed_000C7910 {
    char unknown_00[0x30];
    Info_000C7910 *info;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x54];
    Angles_000C1300 angles;
    float speed;
    char unknown_64[0x2c];
    unsigned int flags;
    char unknown_94[0x3c];
    Vector3 position;
    char unknown_dc[0xc];
    float fall;
    char unknown_ec[0x2c8];
    Speed_000C7910 *speed_info;

    float func_000C9CC0();
};

// One airborne step: no speed under flag 0x200; moves the position at 0xd0 by the speed at 0x60 along the angles at
// 0x54 (func_000C1300) and by the fall speed at 0xe8, which drops by the gravity at 0x3c of the speed info down to
// minus its limit at 0x40. Returns 0.
float Object_000C7910::func_000C9CC0()
{
    Vector3 direction;
    if (flags & 0x200)
        speed = 0.0f;
    data_00257CE8->func_000C1300(&angles, &direction);
    position.x += direction.x * speed;
    position.y += fall;
    position.z += direction.z * speed;
    fall -= speed_info->info->gravity;
    float limit = -speed_info->info->fallLimit;
    if (fall < limit)
        fall = limit;
    return 0.0f;
}
