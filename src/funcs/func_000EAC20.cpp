/* sym: ??0Object_000EA3B0@@QAE@PAUDesc_000EA3B0@@@Z = 0x000EA3B0 */
struct Vector3;
struct Desc_000EA3B0;

int func_000EB750(int event, Vector3 *position);

// The object func_000EA3B0 builds (0x1f4 bytes); 0x4 holds the object it serves.
struct Object_000EA3B0 {
    Object_000EA3B0(Desc_000EA3B0 *desc);
    virtual ~Object_000EA3B0();

    Desc_000EA3B0 *desc;
    char unknown_008[0x98];
    int value_a0;
    int value_a4;
    char unknown_0a8[0x14c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4 and its event handler at 0xe8.
struct Desc_000EA3B0 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xcc];
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000EA3B0 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000EA3B0 for the object, which gains the flags
// 0x9004; the new object takes the object at 0x4 and the description's 0x10 and 0xc at 0xa0 and 0xa4, and becomes the
// object's behaviour, with func_000EB750 its event handler.
void func_000EAC20(Desc_000EA3B0 *desc, Params_000EA3B0 *params)
{
    Object_000EA3B0 *behaviour = new Object_000EA3B0(desc);
    desc->flags |= 0x9004;
    behaviour->desc = desc;
    behaviour->value_a0 = params->value_10;
    behaviour->value_a4 = params->value_0c;
    desc->behaviour = behaviour;
    desc->handler = func_000EB750;
}
