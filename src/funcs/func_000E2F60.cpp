/* sym: ??0Object_000F55E0@@QAE@PAUNode@@HIPAUInit_000F55E0@@@Z = 0x000F5E70 */
/* sym: ??1Object_000F55E0@@UAE@XZ = 0x000F60C0 */
/* sym: ?func_00011C90@Object_000F55E0@@UAEXXZ = 0x000F61D0 */
/* sym: ?func_00011C90_1@Object_000F55E0@@UAEXXZ = 0x000F62B0 */
/* sym: ?func_00011C80@Object_000F55E0@@UAEXH@Z = 0x000F4DD0 */
/* sym: ?func_00011C80_3@Object_000F55E0@@UAEXH@Z = 0x000F4FF0 */
/* sym: ?func_00011C80_4@Object_000F55E0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_000F51A0@Object_000E2F60@@UAEXXZ = 0x000E2BF0 */
/* sym: ?func_000F6770@Object_000E2F60@@UAEXXZ = 0x000E2D60 */
struct Vector3;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    char unknown_08[0x3c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): its event handler at 0xe8.
struct Desc_000E5380 : Node {
    char unknown_44[0xa4];
    int (*handler)(int event, Vector3 *position);
};

// One placement (0x1c bytes).
struct Init_000F55E0 {
    char unknown_00[0x1c];
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000E5380 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Init_000F55E0 *entries;
};

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (0x200 bytes), a link of the chain at 0x44.
struct Object_000F55E0 : Node, Object_000C60C0 {
    Object_000F55E0(Node *owner, int id, unsigned int flags, Init_000F55E0 *init);
    virtual ~Object_000F55E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_000F51A0();
    virtual void func_000F5310();
    virtual void func_000F5380();
    virtual void func_000F53E0();
    virtual void func_000F63E0();
    virtual void func_000F6480();
    virtual void func_000F6500();
    virtual void func_000F54C0();
    virtual void func_000F5510();
    virtual void func_000F5550();
    virtual void func_000F55A0();
    virtual void func_000F6580();
    virtual void func_000F55E0();
    virtual void func_000F6620();
    virtual void func_000F5600();
    virtual void func_000F5620();
    virtual void func_000F66C0();
    virtual void func_000F6700();
    virtual void func_000F5640();
    virtual void func_000F6770();
    virtual void func_000F6B70();
    virtual void func_000F6BF0();
    virtual void func_000F6C40();
    virtual void func_000F6C90();
    virtual void func_000F6D60();
    virtual void func_000F6DD0();
    virtual void func_000F6E30();
    virtual void func_000F6E90();
    virtual void func_000F6F00();
    virtual void func_000F6F70();
    virtual void func_000F6FE0();
    virtual void func_000F7050();
    virtual void func_000F70E0();
    virtual void func_000F7120();
    virtual void func_000F7180();
    virtual void func_000F71D0();
    virtual void func_000F7230();

    char unknown_048[0x1b8];
};

// The Object_000F55E0 child whose table is at 0x1CEAC0 (0x204 bytes): slots 16 (func_000E2BF0) and 35
// (func_000E2D60) differ.
struct Object_000E2F60 : Object_000F55E0 {
    Object_000E2F60(Node *owner, int id, unsigned int flags, Init_000F55E0 *init)
        : Object_000F55E0(owner, id, flags, init)
    {
    }
    virtual void func_000F51A0();
    virtual void func_000F6770();

    int unknown_200;
};

int func_000E2A20(int event, Vector3 *position);

// One of the factories of the table at 0x215D68: each placement of the description makes an Object_000E2F60 under
// the object (first free id in [0x12B2, 0x13B2], flags 0x100), chained after the previous one; then func_000E2A20
// becomes the object's event handler.
void func_000E2F60(Desc_000E5380 *desc, Params_000E5380 *params)
{
    Init_000F55E0 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    for (unsigned int i = 0; i < params->count; i++, entry++) {
        Object_000E2F60 *child =
            new Object_000E2F60(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0x100, entry);
        child->func_000C6090(previous, desc, i);
        previous = child;
    }
    desc->handler = func_000E2A20;
}
