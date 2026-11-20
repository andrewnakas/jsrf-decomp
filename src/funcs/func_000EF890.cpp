/* sym: ??0Object_000EDC30@@QAE@PAUDesc_000EDC30@@@Z = 0x000EDC30 */
struct Vector3;
struct Desc_000EDC30;

// The tuning blocks at 0x21A728 and 0x21A754.
struct Tuning_000EDC30 {
    int unknown_00;
};

struct Extra_000EDC30 {
    int unknown_00;
};

extern Tuning_000EDC30 data_0021A728;
extern Extra_000EDC30 data_0021A754;

int func_000EDB00(int event, Vector3 *position);

// The object func_000EDC30 builds (0x3c8 bytes); 0x4 holds the object it serves.
struct Object_000EDC30 {
    Object_000EDC30(Desc_000EDC30 *desc);
    virtual ~Object_000EDC30();

    Desc_000EDC30 *desc;
    char unknown_008[0x28];
    Tuning_000EDC30 *tuning;
    char unknown_034[0x38];
    int value_6c;
    int value_70;
    char unknown_074[0x60];
    Extra_000EDC30 *extra;
    char unknown_0d8[0x2f0];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, more flags
// at 0xa4, its behaviour at 0xd4 and its event handler at 0xe8.
struct Desc_000EDC30 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0x9c];
    unsigned int flags_a4;
    char unknown_a8[0x28];
    int value_d0;
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000EDC30 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: the object gains the flag 0x4000 at 0xa4, then gets an
// Object_000EDC30 with the tuning blocks at 0x21A728 and 0x21A754 and the description's 0xc and 0x10 at 0x6c and
// 0x70 as its behaviour; 0xd0 is cleared, the flags become 0x8010 and func_000EDB00 is the event handler.
void func_000EF890(Desc_000EDC30 *desc, Params_000EDC30 *params)
{
    desc->flags_a4 |= 0x4000;
    Object_000EDC30 *behaviour = new Object_000EDC30(desc);
    behaviour->desc = desc;
    behaviour->tuning = &data_0021A728;
    behaviour->extra = &data_0021A754;
    behaviour->value_6c = params->value_0c;
    behaviour->value_70 = params->value_10;
    desc->behaviour = behaviour;
    desc->value_d0 = 0;
    desc->flags = 0x8010;
    desc->handler = func_000EDB00;
}
