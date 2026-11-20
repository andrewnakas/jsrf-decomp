/* sym: ??0Object_000E0440@@QAE@PAUDesc_000E0440@@@Z = 0x000E0440 */
struct Vector3;
struct Desc_000E0440;

// The tuning blocks at 0x217D10 and 0x217D3C.
struct Tuning_000E0440 {
    int unknown_00;
};

struct Extra_000E0440 {
    int unknown_00;
};

extern Tuning_000E0440 data_00217D10;
extern Extra_000E0440 data_00217D3C;

int func_000E03A0(int event, Vector3 *position);

// The object func_000E0440 builds (0x138 bytes); 0x4 holds the object it serves.
struct Object_000E0440 {
    Object_000E0440(Desc_000E0440 *desc);
    virtual ~Object_000E0440();

    Desc_000E0440 *desc;
    char unknown_008[0x28];
    Tuning_000E0440 *tuning;
    char unknown_034[0x38];
    int value_6c;
    int value_70;
    char unknown_074[0x18];
    Extra_000E0440 *extra;
    char unknown_090[0xa8];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4 and its event handler at 0xe8.
struct Desc_000E0440 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xc8];
    int value_d0;
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000E0440 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000E0440 for the object, with the tuning blocks at
// 0x217D10 and 0x217D3C and the description's 0xc and 0x10 at 0x6c and 0x70; it becomes the object's behaviour, 0xd0 is
// cleared, the object gains the flags 0x8010 and func_000E03A0 is the event handler.
void func_000E1390(Desc_000E0440 *desc, Params_000E0440 *params)
{
    Object_000E0440 *behaviour = new Object_000E0440(desc);
    behaviour->desc = desc;
    behaviour->tuning = &data_00217D10;
    behaviour->extra = &data_00217D3C;
    behaviour->value_6c = params->value_0c;
    behaviour->value_70 = params->value_10;
    desc->behaviour = behaviour;
    desc->value_d0 = 0;
    desc->flags |= 0x8010;
    desc->handler = func_000E03A0;
}
