/* sym: ??0Object_000D6350@@QAE@PAUDesc_000D6350@@@Z = 0x000D6350 */
struct Vector3;
struct Desc_000D6350;

// The tuning block at 0x217078 (floats and counts).
struct Tuning_000D6350 {
    int unknown_00;
};

extern Tuning_000D6350 data_00217078;

int func_000D62C0(int event, Vector3 *position);

// The object func_000D6350 builds (0x2e0 bytes); 0x4 holds the object it serves.
struct Object_000D6350 {
    Object_000D6350(Desc_000D6350 *desc);
    virtual ~Object_000D6350();

    Desc_000D6350 *desc;
    char unknown_008[0x28];
    Tuning_000D6350 *tuning;
    char unknown_034[0x38];
    int value_6c;
    int value_70;
    char unknown_074[0x26c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4 and its event handler at 0xe8.
struct Desc_000D6350 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xc8];
    int value_d0;
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000D6350 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000D6350 for the object, with the tuning at
// 0x217078 and the description's 0xc and 0x10 at 0x6c and 0x70; it becomes the object's behaviour, 0xd0 is cleared,
// the flags become 0x4010 and func_000D62C0 is the event handler.
void func_000D7720(Desc_000D6350 *desc, Params_000D6350 *params)
{
    Object_000D6350 *behaviour = new Object_000D6350(desc);
    behaviour->desc = desc;
    behaviour->tuning = &data_00217078;
    behaviour->value_6c = params->value_0c;
    behaviour->value_70 = params->value_10;
    desc->behaviour = behaviour;
    desc->value_d0 = 0;
    desc->flags = 0x4010;
    desc->handler = func_000D62C0;
}
