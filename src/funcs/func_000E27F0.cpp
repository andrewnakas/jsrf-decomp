/* sym: ??0Object_000CCE00@@QAE@XZ = 0x000CC620 */
/* sym: ??0Object_000C3D90@@QAE@XZ = 0x000C4090 */
/* sym: ??0Object_000E2470@@QAE@PAUNode@@HI@Z = 0x000E2260 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles.
struct Rotation_000E27F0 {
    int x;
    int y;
    int z;
};

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *result, const Vector3 *point);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The limits a behaviour reads (0x5c bytes).
struct Limits_000E27F0 {
    char unknown_00[0x48];
    int value_48;
    char unknown_4c[0x10];
};

// The states table of the part (0x100 bytes).
struct States_000E27F0 {
    char unknown_00[0x100];
};

// The behaviour (0x108 bytes): the object it serves at 0x4, its limits at 0x30.
struct Object_000CCE00 {
    Object_000CCE00();

    int unknown_00;
    void *owner;
    char unknown_08[0x28];
    Limits_000E27F0 *limits;
    char unknown_34[0xd4];
};

// The 0x18-byte state machine: the object it serves at 0x4, its states at 0x14.
struct Object_000C3D90 {
    Object_000C3D90();

    int unknown_00;
    void *owner;
    char unknown_08[0xc];
    States_000E27F0 *states;
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): its position at 0x44 and angles
// at 0x50, a count at 0x98, points at 0xc8, the chain at 0xd0, the behaviour at 0xd4, the part at 0xd8 and the event
// handler at 0xe8.
struct Desc_000E5380 : Node {
    Vector3 position;
    Rotation_000E27F0 rotation;
    char unknown_5c[0x3c];
    unsigned int count;
    char unknown_9c[0x2c];
    Vector3 *points;
    char unknown_cc[4];
    int chain;
    Object_000CCE00 *behaviour;
    Object_000C3D90 *part;
    char unknown_dc[0xc];
    int (*handler)(int event, Vector3 *position);
};

// The link of a chain (the second base, at 0x44): func_000C6090 puts it after the previous one with its index; its
// position at 0x4, angles at 0x10 and a second position at 0x60.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);

    Vector3 position;
    Rotation_000E27F0 rotation;
    char unknown_1c[0x44];
    Vector3 position_60;
};

// The 0x3d0-byte Node child func_000E2260 builds, a link of the chain at 0x44: a third position at 0xd0, the
// behaviour at 0x3b4.
struct Object_000E2470 : Node, Object_000C60C0 {
    Object_000E2470(Node *owner, int id, unsigned int flags);

    char unknown_0b0[0x20];
    Vector3 position_d0;
    char unknown_0dc[0x2d8];
    Object_000CCE00 *behaviour;
    char unknown_3b8[0x18];
};

extern Limits_000E27F0 data_002182D0;
extern States_000E27F0 data_0021832C;
extern int *data_0021833C;
extern Vector3 *data_0021842C[];

int func_000E2070(int event, Vector3 *position);

// One of the factories of the table at 0x215D68: the object gets an Object_000CCE00 behaviour with the limits at
// 0x2182D0 and an Object_000C3D90 part with the states at 0x21832C, the point list of its count and
// func_000E2070 as its event handler; then each point, moved into the object's frame, gets an Object_000E2470
// (first free id in [0x12B2, 0x13B2]) chained after the previous one.
void func_000E27F0(Desc_000E5380 *desc)
{
    Object_000CCE00 *behaviour = new Object_000CCE00;
    Object_000C3D90 *part = new Object_000C3D90;
    behaviour->limits = &data_002182D0;
    behaviour->owner = desc;
    part->owner = desc;
    part->states = &data_0021832C;
    data_0021833C = &behaviour->limits->value_48;
    desc->behaviour = behaviour;
    desc->part = part;
    desc->points = data_0021842C[desc->count];
    desc->chain = 0;
    desc->handler = func_000E2070;
    func_001BAA00();
    func_001BAAA0(&desc->position.x);
    func_001BB380(desc->rotation.z);
    func_001BB330(desc->rotation.y + 0x8000);
    func_001BB2E0(desc->rotation.x);
    Object_000C60C0 *previous = 0;
    for (unsigned int i = 0; i < desc->count; i++) {
        Object_000E2470 *child = new Object_000E2470(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0);
        child->behaviour = behaviour;
        child->func_000C6090(previous, desc, i);
        previous = child;
        func_001BAB20(&previous->position, &desc->points[i]);
        child->position_d0 = previous->position;
        previous->position_60 = previous->position;
        previous->rotation = desc->rotation;
    }
    func_001BAA50();
}
