struct Vector3 {
    float x;
    float y;
    float z;
};

// Two corners.
struct Box_00017CC0 {
    Vector3 low;
    Vector3 high;
};

struct Item_00016260 {
    int unknown_00;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

extern Object_00016200 data_0022FCE8;

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The owner at 0x4: its position at 0x44, speed at 0x5c, rise at 0x60 and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float speed;
    float rise;
    char unknown_64[0x40];
    unsigned int flags;
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

    void func_000CC270();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 position;
    char unknown_20[0x50];
    Item_00016260 body;
    Item_00016260 head;
    Vector3 center;
    float radius;
};

// While the owner moves (speed or rise) or has flag 0x80, the item at 0x70 gets the box spanning the owner's
// position raised by 3 and the position at 0x14 lowered by 1 (func_00017CC0), the point at 0xf8 is set 7 above
// (func_001BAB20) and the item at 0xb4 gets the box of the radius at 0x104 around it (func_00017D90); both items are
// queued on data_0022FCE8 (func_00016260, -1). Otherwise the items' words at 0x24 and 0x34 are cleared.
void Object_000CCE00::func_000CC270()
{
    if (owner->speed == 0.0f && owner->rise == 0.0f && !(owner->flags & 0x80)) {
        body.unknown_20[5] = 0;
        body.unknown_20[1] = 0;
        head.unknown_20[5] = 0;
        head.unknown_20[1] = 0;
        return;
    }
    {
        Vector3 points[2];
        points[0] = owner->position;
        points[0].y += 3.0f;
        points[1] = position;
        points[1].y -= 1.0f;
        data_0022FCE8.func_00017CC0(&body.box, points, 2);
        data_0022FCE8.func_00016260(&body, -1);
    }
    {
        Vector3 up;
        up.x = 0.0f;
        up.y = 7.0f;
        up.z = 0.0f;
        func_001BAB20(&center, &up);
    }
    data_0022FCE8.func_00017D90(&head.box, &center, 1, radius);
    data_0022FCE8.func_00016260(&head, -1);
}
