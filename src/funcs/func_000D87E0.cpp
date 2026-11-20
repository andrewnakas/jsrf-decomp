struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[0x14];
};

// What func_00018260 reports (16 bytes).
struct Hit_00018260 {
    float unknown_00[4];
};

struct Hits_000C4C60;

// The contact func_000194B0 picks: a point at 0x2c and a normal at 0x48.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 point;
    char unknown_38[0x10];
    Vector3 normal;
};

// The other kind of contact: a point at 0x50 and a normal at 0x6c.
struct OtherContact_000D87E0 {
    char unknown_00[0x50];
    Vector3 point;
    char unknown_5c[0x10];
    Vector3 normal;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The owner at 0x4: position at 0x44, velocity at 0x5c, the last move at 0x74, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    Vector3 velocity;
    char unknown_68[0xc];
    Vector3 moved;
    char unknown_80[0x24];
    unsigned int flags;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE63C (constructor func_000D8A40).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D8A40();

    Object_000C5B50 *owner;
    char unknown_008[0xc];
    Vector3 position;
    char unknown_020[0x48];
    Vector3 normal;
    char unknown_074[0xa8];
    Model_00018260 model;

    void func_000D87E0();
};

// While the owner falls or moves (flag 0x80, or a velocity in x or y): sweeps the model at 0x11c from 3 above the
// owner's position to 1 below the point at 0x14 (func_00018260). On a hit the point and the normal at 0x68 take the
// contact's, the owner's move at 0x74 is measured (func_0014C4C0), its fall speed takes the move's unless flag
// 0x1000000 is set, and flag 0x80 clears; else the fall speed (at most 0) grows by 1/18 down to -1.39 and flag 0x80
// is set. The owner then stands at the point.
void Object_000D8A40::func_000D87E0()
{
    if ((owner->flags & 0x80) || owner->velocity.x != 0.0f || owner->velocity.y != 0.0f) {
        if (model.count > 0 || model.otherCount > 0) {
            Vector3 from = owner->position;
            from.y += 3.0f;
            Vector3 to = position;
            to.y -= 1.0f;
            Hit_00018260 hit;
            if (data_0022FCE8.func_00018260(&model, &from, &to, &hit, 0xffff, -1)) {
                Contact_000C4A90 *contact;
                if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &contact)) {
                    position = contact->point;
                    normal = contact->normal;
                } else {
                    position = ((OtherContact_000D87E0 *)contact)->point;
                    normal = ((OtherContact_000D87E0 *)contact)->normal;
                }
                func_0014C4C0(&owner->moved, &position, &owner->position);
                if (!(owner->flags & 0x1000000)) {
                    owner->velocity.y = owner->moved.y;
                }
                owner->flags &= ~0x80;
                goto stand;
            }
        }
        if (owner->velocity.y > 0.0f) {
            owner->velocity.y = 0.0f;
        }
        owner->velocity.y -= 0.055555556f;
        if (owner->velocity.y < -1.3888888f) {
            owner->velocity.y = -1.3888888f;
        }
        owner->flags |= 0x80;
    stand:
        owner->position = position;
    }
}
