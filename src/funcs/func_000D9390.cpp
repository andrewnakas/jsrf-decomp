/* sym: ??0Object_000D8A40@@QAE@PAUDesc_000D8A40@@@Z = 0x000D8A40 */
struct Vector3;
struct Desc_000D8A40;

int func_000D7CF0(int event, Vector3 *position);

// The object func_000D8A40 builds (0x1d0 bytes); 0x4 holds the object it serves.
struct Object_000D8A40 {
    Object_000D8A40(Desc_000D8A40 *desc);
    virtual ~Object_000D8A40();

    Desc_000D8A40 *desc;
    char unknown_008[0x34];
    int value_3c;
    int value_40;
    char unknown_044[0x18c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4 and its event handler at 0xe8.
struct Desc_000D8A40 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xcc];
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000D8A40 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000D8A40 for the object, which gains the flags
// 0x100; the new object takes the object at 0x4 and the description's 0x10 and 0xc at 0x40 and 0x3c, and becomes the
// object's behaviour, with func_000D7CF0 its event handler.
void func_000D9390(Desc_000D8A40 *desc, Params_000D8A40 *params)
{
    Object_000D8A40 *behaviour = new Object_000D8A40(desc);
    desc->flags |= 0x100;
    behaviour->desc = desc;
    behaviour->value_40 = params->value_10;
    behaviour->value_3c = params->value_0c;
    desc->behaviour = behaviour;
    desc->handler = func_000D7CF0;
}
