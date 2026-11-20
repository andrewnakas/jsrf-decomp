/* sym: ??0Object_000E7770@@QAE@PAUNode@@HIPAUInit_000E7770@@I@Z = 0x000E7A60 */
/* sym: ?func_000CD1E0@Object_000E7D70@@UAEXXZ = 0x00011C90 */
/* sym: ?func_00011C80@Object_000E7D70@@UAEXH@Z = 0x000E7A00 */
/* sym: ?func_00011C80_1@Object_000E7D70@@UAEXH@Z = 0x000AEE80 */
struct Vector3;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    int func_0003A580(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x3c];
};

// One placement (0x1c bytes); the value at 0x18 over ten numbers the first.
struct Init_000E7770 {
    char unknown_00[0x18];
    unsigned int value_18;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

struct Desc_000E5380;

// The behaviour func_000E7D70 builds (0x30 bytes, table 0x1CEE30): slot 0 does nothing, slot 3 runs slot 2.
struct Object_000E7D70 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);

    Desc_000E5380 *desc;
    char unknown_08[0x28];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): a Node with its behaviour at
// 0xd4 and its event handler at 0xe8.
struct Desc_000E5380 : Node {
    char unknown_44[0x60];
    unsigned int flags_a4;
    char unknown_a8[0x2c];
    Object_000E7D70 *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: a count at 0xc and the placements at 0x10.
struct Params_000E7D70 {
    int kind;
    char unknown_04[8];
    unsigned int count;
    Init_000E7770 *entries;
};

// The link of a chain: func_000C6090 puts it after the previous one (or first in the owner's 0xd0) with its index.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
};

// The Node child func_000E7A60 builds (0x104 bytes), a link of the chain at 0x44.
struct Object_000E7770 : Node, Object_000C60C0 {
    Object_000E7770(Node *owner, int id, unsigned int flags, Init_000E7770 *init, unsigned int number);

    char unknown_048[0xbc];
};

int func_000E7670(int event, Vector3 *position);

// Entry of the factory table at 0x215D68: each placement whose number (counted up from the first one's 0x18 over
// ten) func_0003A580 of data_001EFFB0 does not report makes an Object_000E7770 under the object (first free id in
// [0x12B2, 0x13B2]), chained after the previous one; then the object gets func_000E7670 as its event handler, the flag
// 0x100 and an Object_000E7D70 as its behaviour, and the flags 0x2020 at 0xa4 when no link was made.
void func_000E7D70(Desc_000E5380 *desc, Params_000E7D70 *params)
{
    Init_000E7770 *entry = params->entries;
    Object_000C60C0 *previous = 0;
    unsigned int number = entry->value_18 / 10;
    for (unsigned int i = 0; i < params->count; i++, entry++, number++) {
        if (!data_001EFFB0.func_0003A580(number)) {
            Object_000E7770 *object =
                new Object_000E7770(desc, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0, entry, number);
            object->func_000C6090(previous, desc, i);
            previous = object;
        }
    }
    desc->handler = func_000E7670;
    desc->flags |= 0x100;
    Object_000E7D70 *behaviour = new Object_000E7D70;
    desc->behaviour = behaviour;
    behaviour->desc = desc;
    if (!previous) {
        desc->flags_a4 |= 0x2020;
    }
}
