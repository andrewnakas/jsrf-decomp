struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
};

extern Object_00157F10 *data_00257CE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000C5B50 {
    int func_000C5B10(int kind, void *data);
};

// Player 0x2c: a word per slot at 0xfec.
struct Player_000C8D30 {
    char unknown_0000[0xfec];
    int slots[1];
};

// The tuning values: the top speed at 0xc.
struct Tuning_000C8D30 {
    char unknown_00[0xc];
    float maxSpeed;
};

struct Body_000C8D30 {
    Tuning_000C8D30 *tuning;
};

// An entry of the list at 0x39c: its kind, two directions at 0x1c and 0x2c, the speed at 0x28, the next at 0x38.
struct Entry_000C8D30 {
    int kind;
    char unknown_04[0x18];
    Vector3 fallback;
    float speed;
    Vector3 direction;
    Entry_000C8D30 *next;
};

void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    char unknown_064[0x2c];
    unsigned int flags;
    char unknown_094[0x1c];
    Object_000C5B50 *effects;
    char unknown_0b4[8];
    int mode;
    char unknown_0c0[0x10];
    Vector3 point;
    char unknown_0dc[0x50];
    Vector3 push;
    char unknown_138[4];
    int slot;
    char unknown_140[0x40];
    unsigned int count;
    char unknown_184[0xb8];
    unsigned int flags2;
    char unknown_240[0x158];
    Body_000C8D30 *body;
    Entry_000C8D30 *entries;

    void func_000C83A0();
    void func_000C8400();
    void func_000C8460();
    void func_000C84B0();
    void func_000C8D30();
};

// When the list at 0x39c has an entry of kind 9: takes its flat direction (func_0014CD50 of 0x2c, y cleared; the one
// at 0x1c when that is zero, else normalized) as the push at 0x12c, compares it with the facing (func_000C1300 of
// the angles): ahead (dot above 0.7) func_000C83A0, behind (below -0.7) func_000C8400, else func_000C8460 or
// func_000C84B0 by the side (the cross product's y). Speed 1.39 at 0x60; the entry's speed is clamped to 0 - the
// tuning's top speed and the point at 0xd0 moves by it plus 1 along the push. Updates the flags, frees the player
// slot at 0x13c, starts effect 0x10 at the position (func_000C5B10 of 0xb0) and after 10 times goes to mode 0x1b.
void Object_000C7910::func_000C8D30()
{
    Entry_000C8D30 *entry;
    for (entry = entries; entry; entry = entry->next) {
        if (entry->kind == 9)
            break;
    }
    if (!entry) {
        return;
    }
    func_0014CD50(&push, &entry->direction);
    push.y = 0.0f;
    if (push.x == 0.0f && push.z == 0.0f) {
        func_0014CD50(&push, &entry->fallback);
    } else {
        func_0014C410(&push, &push);
    }
    Vector3 facing;
    data_00257CE8->func_000C1300(&angles, &facing);
    float dot = func_0014C800(&push, &facing);
    speed = 1.3888888f;
    if (dot > 0.7f) {
        func_000C83A0();
    } else if (dot < -0.7f) {
        func_000C8400();
    } else {
        Vector3 side;
        func_0014C3B0(&side, &facing, &push);
        if (side.y >= 0.0f) {
            func_000C8460();
        } else {
            func_000C84B0();
        }
    }
    speed = 1.3888888f;
    if (entry->speed < 0.0f || entry->speed > body->tuning->maxSpeed) {
        entry->speed = body->tuning->maxSpeed;
    }
    func_0014C730(&point, &push, entry->speed + 1.0f);
    flags = (flags & ~0x7008006) | 0xa00000;
    flags2 &= ~0x41b;
    if (slot >= 0) {
        Player_000C8D30 *player = (Player_000C8D30 *)data_0022FCE0->func_000128C0(0x2c);
        if (player) {
            player->slots[slot] = 0;
        }
        slot = -1;
    }
    effects->func_000C5B10(0x10, &position);
    if (++count >= 10) {
        mode = 0x1b;
        flags |= 0x400000;
    }
}
