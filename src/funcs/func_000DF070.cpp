/* sym: ?func_000CBF90@Object_000DCBC0@@UAEXXZ = 0x000DF070 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    int value_00;
    char unknown_04[0x78];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The object in data_00257CE8; func_00157F10 is the engine's (it returns 0).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DEB0(int key, int value);
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

void func_0005DAA0(void *pointer);

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float value_5c;
    char unknown_60[4];
    int area;
    int count;
    char unknown_6c[0x38];
    unsigned int flags;
    Vector3 *target;

    int func_000C59A0();
    int func_000C5B10(int message, void *data);
};

// func_00033800 only returns 1; this unit calls it directly with the owner in ecx.
struct Object_000265A0 {
    int func_00033800(int unused);
};

struct Limits_000CC020 {
    int value_00;
    union {
        float limit;
        int value_04;
    };
    char unknown_08[8];
    float rate;
    char unknown_14[4];
    float range;
    char unknown_1c[0x1c];
    int value_38;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    int func_000CC040();
    void func_000CC4B0(int value);
    float func_000CCAE0();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first); slots 8 and 16
// stay Object_000CCE00's.
struct Object_000DCBC0 : Object_000CCE00 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DCBC0();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();

    int func_000DDCB0();
    void func_000DE6C0();

    char unknown_034[0xdc];
    int value_110;
    char unknown_114[0x3c];
    char point_150[0x50];
    void *items[3];
    char unknown_1ac[0x14];
    int next;
    char unknown_1c4[0xe4];
    void *mesh;
    char unknown_2ac[0x18];
    int effect;
    char unknown_2c8[8];
    int key;
};

// Slot 13: counts the owner's 0x68 up; on the first call 5 at 0x1c0, the owner's 0x5c cleared and its target the
// point at 0x7c of data_00257CE4; from 180 on, the owner loses flags 0x20000 and 2, state 2 and the count restarts.
// Then func_000DE6C0.
void Object_000DCBC0::func_000CBF90()
{
    if (owner->count++ == 0) {
        next = 5;
        owner->value_5c = 0;
        owner->target = &data_00257CE4->unknown_7c;
        func_000DE6C0();
        return;
    }
    if (owner->count >= 180) {
        owner->flags &= ~0x20000;
        state = 2;
        owner->flags &= ~2;
        owner->count = 0;
    }
    func_000DE6C0();
}
