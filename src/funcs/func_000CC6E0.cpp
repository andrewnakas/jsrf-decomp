/* sym: ?func_000CD1E0@Object_000CCE00@@UAEXXZ = 0x000CC6E0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// One of the owner's parts (a list through 0x74): flags at 0x4c, its posed point at 0x60, a source at 0xa8.
struct Part_000CC6E0 {
    char unknown_00[0x4c];
    unsigned int flags;
    char unknown_50[0x10];
    Vector3 point;
    char unknown_6c[8];
    Part_000CC6E0 *next;
    char unknown_78[0x30];
    Vector3 *source;
};

// The object a behaviour serves: position 0x44, angle 0x54, speed 0x5c, a value at 0x70, a point count at 0x98,
// flags at 0xa4, the posed centre at 0xac, the points at 0xc8 and the parts at 0xd0 (two held at 0xe0 and 0xe4).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[4];
    int angle;
    char unknown_58[4];
    float speed;
    char unknown_60[0x10];
    float height;
    char unknown_74[0x24];
    unsigned int count;
    char unknown_9c[8];
    unsigned int flags;
    char unknown_a8[4];
    Vector3 center;
    char unknown_b8[0x10];
    Vector3 *points;
    char unknown_cc[4];
    Part_000CC6E0 *parts;
    char unknown_d4[0xc];
    Part_000CC6E0 *held;
    Part_000CC6E0 *other;

    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

void func_001BAA00();
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE320.
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

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[8];
    Vector3 position;
    char unknown_20[0x4c];
    int handle;

    void func_000CC270();
};

extern void (Object_000CCE00::*data_00216398[])();

// Slot 0. With bit 0x20 of the owner's flags it only releases its handle at 0x6c. Bit 0x10 marks every part, drops
// the two held ones (the other one back on data_00257CE4's point) and sets state 11. The state's handler runs
// (data_00216398); bit 0x20 marks the parts. Then the parts' points (counting those with bit 0x40) and the centre
// are posed at the owner, func_000CC270 runs at the position, and while there are parts (or points), the owner
// moves (0x5c) and is low (0x70 under 100), the handle follows the owner (func_000C5B40) or is taken by the count
// (func_000C5B10 with 2 over 3, 1 over 1, else 0); otherwise it is released.
void Object_000CCE00::func_000CD1E0()
{
    if (owner->flags & 0x20) {
        if (handle != -1) {
            owner->func_000C5B50(&handle);
        }
        return;
    }
    Part_000CC6E0 *part = owner->parts;
    if (owner->flags & 0x10) {
        for (; part; part = part->next) {
            part->flags |= 0x10;
        }
        if (owner->held) {
            owner->held = owner->other;
        }
        if (owner->other) {
            owner->other = owner->held;
            owner->other->source = &data_00257CE4->point;
        }
        owner->held = 0;
        owner->other = 0;
        state = 0xb;
    }
    (this->*data_00216398[state])();
    if (owner->flags & 0x20) {
        for (Part_000CC6E0 *part = owner->parts; part; part = part->next) {
            part->flags |= 0x20;
        }
    }
    func_001BAA00();
    unsigned int count = 0;
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angle + 0x8000);
    int i = 0;
    for (Part_000CC6E0 *part = owner->parts; part; part = part->next) {
        func_001BAB20(&part->point, &owner->points[i]);
        if (part->flags & 0x40) {
            count++;
        }
        i++;
    }
    func_001BAB20(&owner->center, &owner->points[owner->count]);
    func_001BAA50();
    func_001BAAA0(&position.x);
    func_001BB330(owner->angle + 0x8000);
    func_000CC270();
    if (!owner->parts && owner->count > 0) {
        count = owner->count;
    }
    if (count > 0) {
        if (owner->speed > 0.0f && owner->height < 100.0f) {
            if (handle != -1) {
                owner->func_000C5B40(handle, &owner->position);
            } else if (count > 3) {
                handle = owner->func_000C5B10(2, &owner->position);
            } else if (count > 1) {
                handle = owner->func_000C5B10(1, &owner->position);
            } else {
                handle = owner->func_000C5B10(0, &owner->position);
            }
        } else {
            count = 0;
        }
    }
    if (count == 0) {
        owner->func_000C5B50(&handle);
    }
    func_001BAA50();
}
