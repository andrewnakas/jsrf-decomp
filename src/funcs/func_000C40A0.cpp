struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C5B50;

// A link of the per-area lists of data_00257CE4.
struct Link_000C6150 {
    Object_000C5B50 *object;
    Link_000C6150 *next;
};

struct Object_00066980;

// The object in data_00257CE4: a list of objects per area at 0x4, its points at 0x7c, 0x88 and 0x94.
struct Object_000C1270 {
    int unknown_00;
    Link_000C6150 *lists[29];
    Object_00066980 *clock;
    Vector3 point;
    Vector3 point_88;
    Vector3 point_94;
};

extern Object_000C1270 *data_00257CE4;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// A link of the owner's chain at 0xd0 (the second base of the objects the factories build): flags at 0x4c, the next
// link at 0x74.
struct Item_000C3DC0 {
    char unknown_00[0x24];
    Vector3 position;
    char unknown_30[0x1c];
    unsigned int flags;
    char unknown_50[0x24];
    Item_000C3DC0 *next;
};

// The counts the machine works with.
struct Source_000C3DA0 {
    int first;
    int second;
    int value;
    float level;
    unsigned int *clock;
};

// The object a behaviour serves.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    int value_5c;
    char unknown_60[0x10];
    float level;
    char unknown_74[0x28];
    int area;
    char unknown_a0[4];
    unsigned int flags;
    Vector3 *target;
    char unknown_ac[0x24];
    Item_000C3DC0 *first;
    char unknown_d4[0xc];
    Object_000C5B50 *leader;
    Object_000C5B50 *follower;
};

// The base of two small state machines (tables 0x1CDDB8 and 0x1CDDCC): slots 0 and 1 are pure, slots 2 and 3
// empty, slot 4 the destructor.
struct Object_000C4070 {
    virtual void func_000C3D90() = 0;
    virtual void func_00011C90() = 0;
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000C4070() {}

    Object_000C5B50 *owner;
};

// Runs the handler of its current state (table 0x1CDDB8; the handlers are in data_00216148).
struct Object_000C3D90 : Object_000C4070 {
    virtual void func_000C3D90();
    virtual void func_00011C90();

    int state;
    int value_0c;
    Item_000C3DC0 *current;
    Source_000C3DA0 *source;

    void func_000C3DC0();
    void func_000C3F90(Vector3 *position);
    void func_000C40A0();
    void func_000C3E60();
    void func_000C41F0();
};

// Handler 2: under the owner's flag 0x10 the owner gets flag 8 and the state is 3. While the owner's level at 0x70
// is within the source's, data_00257CE4's first word is not negative and the owner lacks flag 0x2000, the count at
// 0xc runs down; at 0 it starts again (1 under the owner's flag 0x400, else the source's first count) and the next
// link from 0x10 with flag 0x40 gets flag 2 and is started at its position (func_000C3F90). Otherwise the link and
// the count are cleared. With no link left the owner gets flag 8, 0x5c and the count are cleared, the state is 3
// and the owner's follower at 0xe4 lets go of it (its target goes back to the point of data_00257CE4).
void Object_000C3D90::func_000C40A0()
{
    unsigned int flags = owner->flags;
    if (flags & 0x10) {
        state = 3;
        owner->flags |= 8;
        return;
    }
    if (!(owner->level > source->level) && data_00257CE4->unknown_00 >= 0 && !(flags & 0x2000)) {
        if (--value_0c <= 0) {
            if (owner->flags & 0x400) {
                value_0c = 1;
            } else {
                value_0c = source->first;
            }
            for (; current; current = current->next) {
                if (current->flags & 0x40) {
                    current->flags |= 2;
                    func_000C3F90(&current->position);
                    current = current->next;
                    break;
                }
            }
        }
    } else {
        current = 0;
        value_0c = 0;
    }
    if (!current) {
        owner->flags |= 8;
        state = 3;
        owner->value_5c = 0;
        value_0c = 0;
        Object_000C5B50 *follower = owner->follower;
        if (follower) {
            follower->leader = 0;
            follower->target = &data_00257CE4->point;
            owner->follower = 0;
        }
    }
}
