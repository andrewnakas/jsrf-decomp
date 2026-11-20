/* sym: ??0Object_000E5FF0@@QAE@PAUDesc_000E5FF0@@@Z = 0x000E5FF0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Desc_000E5FF0;

// The object func_000E5FF0 builds (0x184 bytes); 0x4 holds the object it serves.
struct Object_000E5FF0 {
    Object_000E5FF0(Desc_000E5FF0 *desc);
    virtual ~Object_000E5FF0();

    Desc_000E5FF0 *desc;
    char unknown_008[0x17c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, positions at
// 0x44, 0x50 and 0x80, its behaviour at 0xd4.
struct Desc_000E5FF0 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0x3c];
    Vector3 position;
    Vector3 target;
    char unknown_5c[0x24];
    Vector3 origin;
    char unknown_8c[0x44];
    int value_d0;
    void *behaviour;
};

// The description func_000C0B30 hands the factory: two points at 0x10.
struct Params_000E5FF0 {
    int kind;
    char unknown_04[0xc];
    Vector3 *points;
};

// One of the factories of the table at 0x215D68: builds an Object_000E5FF0 for the object, which gains the flag 4
// and takes it as its behaviour (0xd0 cleared); the description's first point becomes both the origin at 0x80 and
// the position at 0x44, the second the target at 0x50.
void func_000E6820(Desc_000E5FF0 *desc, Params_000E5FF0 *params)
{
    Object_000E5FF0 *behaviour = new Object_000E5FF0(desc);
    desc->flags |= 4;
    behaviour->desc = desc;
    desc->behaviour = behaviour;
    desc->value_d0 = 0;
    Vector3 *points = params->points;
    desc->origin = points[0];
    desc->position = points[0];
    desc->target = points[1];
}
