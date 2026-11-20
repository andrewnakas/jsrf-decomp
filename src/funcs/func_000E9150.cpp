/* sym: ??0Object_000E7F50@@QAE@PAUDesc_000E7F50@@@Z = 0x000E7F50 */
struct Vector3;
struct Desc_000E7F50;

// The tuning block at 0x219030 (floats and counts).
struct Tuning_000E7F50 {
    int unknown_00;
};

extern Tuning_000E7F50 data_00219030;

int func_000E7EC0(int event, Vector3 *position);

// The object func_000E7F50 builds (0x2e0 bytes); 0x4 holds the object it serves.
struct Object_000E7F50 {
    Object_000E7F50(Desc_000E7F50 *desc);
    virtual ~Object_000E7F50();

    Desc_000E7F50 *desc;
    char unknown_008[0x28];
    Tuning_000E7F50 *tuning;
    char unknown_034[0x38];
    int value_6c;
    int value_70;
    char unknown_074[0x26c];
};

// The object the factories of the table at 0x215D68 serve (func_000C0B30 makes it): Node flags at 0x4, its behaviour
// at 0xd4 and its event handler at 0xe8.
struct Desc_000E7F50 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xc8];
    int value_d0;
    void *behaviour;
    char unknown_d8[0x10];
    int (*handler)(int event, Vector3 *position);
};

// The description func_000C0B30 hands the factory: its kind first.
struct Params_000E7F50 {
    int kind;
    char unknown_04[8];
    int value_0c;
    int value_10;
};

// One of the factories of the table at 0x215D68: builds an Object_000E7F50 for the object, with the tuning at
// 0x219030 and the description's 0xc and 0x10 at 0x6c and 0x70; it becomes the object's behaviour, 0xd0 is cleared,
// the flags become 0x5010 and func_000E7EC0 is the event handler.
void func_000E9150(Desc_000E7F50 *desc, Params_000E7F50 *params)
{
    Object_000E7F50 *behaviour = new Object_000E7F50(desc);
    behaviour->desc = desc;
    behaviour->tuning = &data_00219030;
    behaviour->value_6c = params->value_0c;
    behaviour->value_70 = params->value_10;
    desc->behaviour = behaviour;
    desc->value_d0 = 0;
    desc->flags = 0x5010;
    desc->handler = func_000E7EC0;
}
