/* sym: ?func_000CBCD0@Object_000DCBC0@@UAEXXZ = 0x000DD670 */
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

struct Box_000CBE60 {
    char unknown_00[0x18];
    Vector3 center;
    char unknown_24[8];
};

struct Boxes_000CBE60 {
    int count;
    Box_000CBE60 *boxes;
};

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    Boxes_000CBE60 *data;

    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

// The object in data_00257CE8; func_00157F10 is the engine's (it returns 0).
struct Object_00157F10 {
    int func_00157F10(void *point, int value);
    int func_000C1D40(int *effect, int *second, int *third);
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DEB0(int key, int value);
    void func_0006DF30(int key);
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

void func_0005DAA0(void *pointer);
void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind);
void func_000FEC30(int value, const Vector3 *position);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void func_001BA9C0();
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

// The model (the holder's first word).
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000DCBC0 {
    Object_00047470 *model;
};

struct Angles_000C5B50 {
    int x;
    int y;
    int z;
};

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C5B50 angles;
    float value_5c;
    float value_60;
    int area;
    int count;
    char unknown_6c[4];
    float level;
    char unknown_74[0xc];
    Vector3 home;
    Angles_000C5B50 home_angles;
    char unknown_98[4];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
    Vector3 *target;

    int func_000C59A0();
    int func_000C5A10();
    void func_000C5AD0(int amount);
    void func_000C5B40(int id, void *position);
    int func_000C5B70(int handle);
    int func_000C5B10(int message, void *data);
};

// func_00033800 only returns 1; this unit calls it directly with the owner in ecx.
struct Object_000265A0 {
    int func_00033800(int unused);
};

struct Limits_000CC020 {
    int value_00;
    float limit;
    float limit_08;
    char unknown_0c[4];
    float rate;
    float decay;
    float range;
    char unknown_1c[0x1c];
    int value_38;
};

// The points at 0x114, 16 bytes each.
struct Point_000DCBC0 {
    Vector3 position;
    int unknown_0c;
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int argument);
};

extern Object_00046670 data_001F93C8;

extern int data_0021798C;
extern int data_00217998;
extern int data_0021799C;
extern Vector3 data_00217A10;

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
    void func_000CC4B0(float value);
    float func_000CCAE0();
    void func_000CC270();
    void func_000CCE00();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    Vector3 start;
    char unknown_20[0xc];
    float height;
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
    void func_000DF320();
    void func_000DE510();
    void func_000DDE20();

    char unknown_034[0x2c];
    Vector3 point;
    int handle;
    char unknown_070[0x98];
    int value_108;
    char unknown_10c[4];
    int value_110;
    Point_000DCBC0 *points;
    int index;
    int angle;
    char unknown_120[0x24];
    Vector3 position;
    char point_150[0x10];
    int value_160;
    char unknown_164[4];
    int value_168;
    float value_16c;
    float value_170;
    float value_174;
    int value_178;
    int value_17c;
    Holder_000DCBC0 *holder;
    char unknown_184[0x1c];
    void *items[3];
    char unknown_1ac[0x14];
    int next;
    int value_1c4;
    int value_1c8;
    char unknown_1cc[0xdc];
    void *mesh;
    char unknown_2ac[0x18];
    int effect;
    int value_2c8;
    int value_2cc;
    int key;
    int value_2d4;
};

// One handler per state.
extern void (Object_000DCBC0::*data_00217A20[])();

// Slot 5: puts the owner back at its home (0x80), also kept at 0x14, with 0.1 at 0x60 and 0x8c copied to 0x50; aims
// it at the second point of 0x114 when 0x110 is above 1 (else the first), clears its count, gives it flags 0x101,
// resets the fields from 0x160 and moves to state 1; the height at 0x2c is func_000466C0 of its position.
void Object_000DCBC0::func_000CBCD0()
{
    start = owner->home;
    owner->position = owner->home;
    value_174 = start.y;
    owner->value_5c = 0;
    owner->value_60 = 0.1f;
    owner->angles = owner->home_angles;
    if ((unsigned int)value_110 > 1) {
        index = 1;
    } else {
        index = 0;
    }
    owner->target = &points[index].position;
    index = 1;
    owner->count = 0;
    owner->flags |= 0x101;
    state = 1;
    value_1c4 = 7;
    next = 7;
    value_160 = 0;
    count = 0;
    value_17c = 0;
    value_2d4 = 0;
    value_168 = 0;
    value_16c = 1.0f;
    value_170 = 1.0f;
    value_178 = -1;
    height = data_001F93C8.func_000466C0(&owner->position, -1);
}
