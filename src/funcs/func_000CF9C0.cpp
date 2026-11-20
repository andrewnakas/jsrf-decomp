/* sym: ??0Object_000CE9D0@@QAE@PAUDesc_000CF9C0@@@Z = 0x000CE9D0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x3c];
};

int func_000CD8B0(int event, Vector3 *position);

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node with its behaviour at
// 0xd4 and its event handler at 0xe8.
struct Desc_000CF9C0 : Node {
    Vector3 position;
    char unknown_50[4];
    int angle;
    char unknown_58[0x28];
    Vector3 home;
    char unknown_8c[0x48];
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// One placement: a position and an angle.
struct Entry_000CF9C0 {
    Vector3 position;
    int angle;
};

// The description func_000C0B30 hands the factory: the placements at 0x10.
struct Params_000CF9C0 {
    int kind;
    char unknown_04[0xc];
    Entry_000CF9C0 *entries;
};

// The behaviour func_000CE9D0 builds (0x140 bytes); 0x4 holds the object it serves.
struct Object_000CE9D0 {
    Object_000CE9D0(Desc_000CF9C0 *desc);

    int unknown_00;
    Desc_000CF9C0 *desc;
    char unknown_08[0x138];
};

// One of the factories of the table at 0x215D68: the object gets an Object_000CE9D0 as its behaviour, flags 0x8004,
// the first placement's position (at 0x44 and as its home at 0x80) and angle (0x54), and func_000CD8B0 as its event
// handler.
void func_000CF9C0(Desc_000CF9C0 *desc, Params_000CF9C0 *params)
{
    Object_000CE9D0 *behaviour = new Object_000CE9D0(desc);
    desc->flags |= 0x8004;
    behaviour->desc = desc;
    Entry_000CF9C0 *entry = params->entries;
    desc->home = entry->position;
    desc->position = entry->position;
    desc->angle = entry->angle;
    desc->behaviour = behaviour;
    desc->handler = func_000CD8B0;
}
