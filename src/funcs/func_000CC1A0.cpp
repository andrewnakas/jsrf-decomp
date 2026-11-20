/* const: 0x2001b */
struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class. Its position at 0x44, its box at 0x64, its list at
// 0x9c, a point followers aim at (0xac) and its leader and follower at 0xe0 and 0xe4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x14];
    int area;
    char unknown_68[0x34];
    int group;
    char unknown_a0[4];
    unsigned int flags;
    Vector3 *target;
    Vector3 trail;
    char unknown_b8[0x28];
    Object_000C5B50 *leader;
    Object_000C5B50 *follower;

    void func_000C5B50(int *handle);
};

struct Object_00066980;

// A link of the per-list chains of data_00257CE4.
struct Link_000C6150 {
    Object_000C5B50 *object;
    Link_000C6150 *next;
};

// The object in data_00257CE4: the lists at 0x4, its point at 0x7c.
struct Object_000C1270 {
    int unknown_00;
    Link_000C6150 *lists[29];
    Object_00066980 *clock;
    Vector3 point;
};

extern Object_000C1270 *data_00257CE4;

struct Limits_000CC020 {
    char unknown_00[0x54];
    int limit;
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

    void func_000CCE00();
    void func_000CC1A0();

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Limits_000CC020 *limits;
};

// Looks through the owner's list in data_00257CE4 for another free object (none of flags 0x2001b, no leader) in
// the owner's box; the one of the two nearer to the point of data_00257CE4 (func_0014C530) leads: the other one
// joins the end of its chain of followers and aims at the last one's trail point at 0xac.
void Object_000CCE00::func_000CC1A0()
{
    Object_000C5B50 *owner = this->owner;
    for (Link_000C6150 *link = data_00257CE4->lists[owner->group]; link; link = link->next) {
        Object_000C5B50 *other = link->object;
        if (other != owner && !(other->flags & 0x2001b) && !other->leader && other->area == owner->area) {
            float distance = func_0014C530(&owner->position, &data_00257CE4->point);
            Object_000C5B50 *last;
            Object_000C5B50 *joining;
            if (func_0014C530(&link->object->position, &data_00257CE4->point) >= distance) {
                last = this->owner;
                joining = link->object;
            } else {
                last = link->object;
                joining = this->owner;
            }
            while (last->follower) {
                last = last->follower;
            }
            last->follower = joining;
            joining->leader = last;
            joining->target = &last->trail;
            return;
        }
    }
}
