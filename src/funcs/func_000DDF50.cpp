/* sym: ??0Object_000DCBC0@@QAE@PAUDesc_000DCBC0@@@Z = 0x000DCBC0 */
/* sym: ??0Object_000C41B0@@QAE@XZ = 0x000C44D0 */
struct Vector3;
struct Desc_000DCBC0;

// The tuning block at 0x217930.
struct Tuning_000DCBC0 {
    int unknown_00;
};

extern Tuning_000DCBC0 data_00217930;

// The helper's block at 0x21798C (read as an int elsewhere).
extern int data_0021798C;

int func_000DC9F0(int event, Vector3 *position);

// The object func_000DCBC0 builds (0x2dc bytes); 0x4 holds the object it serves.
struct Object_000DCBC0 {
    Object_000DCBC0(Desc_000DCBC0 *desc);
    virtual ~Object_000DCBC0();

    Desc_000DCBC0 *desc;
    char unknown_008[0x28];
    Tuning_000DCBC0 *tuning;
    char unknown_034[0xdc];
    int value_110;
    int value_114;
    char unknown_118[0x1c4];
};

// The helper func_000C44D0 builds (0x1c bytes).
struct Object_000C41B0 {
    Object_000C41B0();
    virtual ~Object_000C41B0();

    Desc_000DCBC0 *desc;
    char unknown_08[0xc];
    int *extra;
    char unknown_18[4];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4, a helper at 0xd8 and its event handler at 0xe8.
struct Desc_000DCBC0 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xc8];
    int value_d0;
    Object_000DCBC0 *behaviour;
    Object_000C41B0 *helper;
    char unknown_dc[0xc];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000DCBC0 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000DCBC0 (tuning 0x217930, the description's 0x10
// and 0xc at 0x114 and 0x110) and an Object_000C41B0 helper (0x21798C) for the object, which gains the flag 0x100 and
// takes them at 0xd4 and 0xd8; 0xd0 is cleared and func_000DC9F0 is the event handler.
void func_000DDF50(Desc_000DCBC0 *desc, Params_000DCBC0 *params)
{
    Object_000DCBC0 *behaviour = new Object_000DCBC0(desc);
    Object_000C41B0 *helper = new Object_000C41B0;
    desc->flags |= 0x100;
    behaviour->desc = desc;
    behaviour->tuning = &data_00217930;
    behaviour->value_114 = params->value_10;
    behaviour->value_110 = params->value_0c;
    helper->desc = desc;
    helper->extra = &data_0021798C;
    desc->behaviour = behaviour;
    desc->helper = helper;
    desc->value_d0 = 0;
    desc->handler = func_000DC9F0;
}
