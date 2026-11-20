/* sym: ?func_00011C90@Object_000F1820@@UAEXXZ = 0x000F0DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x4c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int amount);
    void func_000C5B50(int *handle);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

void func_000FEC30(int value, const Vector3 *position);

// The posed part at 0x78.
struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

extern unsigned int data_0021AFD0[4];
extern Vector3 data_0021AFE0[4];

// The base of the owner's behaviours (table 0x1CE304): slot 0 is pure, slots 2 and 3 take an argument, slot 4 is
// the destructor.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
};

// The state machine whose table is at 0x1CF02C (constructor func_000F1820), made by func_000F1FC0.
struct Object_000F1820 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();

    Object_000C5B50 *owner;
    char unknown_008[0x28];
    int done;
    float previous[4];
    char unknown_044[0x34];
    Object_00047470 *part;
    char unknown_07c[0xf0];
    int sounds[4];
    float values[4];
    int seconds[4];
    char unknown_19c[4];
    int handles[3];
};

// Slot 1: unless the owner has flag 0x2000, clears its flag 0x1000000 and for the four sounds at 0x16c: an open one
// that func_000C1D40 on data_00257CE8 accepts (with 0x18c and 0x17c) gives effect 0x22 of object 0xe8 at the point
// data_0021AFE0 on the part's matrix data_0021AFD0 and has the owner release the three handles at 0x1a0; a value at
// 0x17c that changed from 0x34 sets the owner's flag 0x1000000. A sum of 2 or more sets 0x4000000; with all four
// sounds closed the owner gets 0x2000 and 0x20, func_000C5AD0(1), and 0x30 is set, otherwise func_000FEC30 gets the
// owner's 0x9c and position.
void Object_000F1820::func_00011C90()
{
    if (owner->flags & 0x2000) {
        return;
    }
    unsigned int closed = 0;
    float total = 0.0f;
    owner->flags &= ~0x1000000;
    for (unsigned int i = 0; i < 4; i++) {
        if (sounds[i] != -1) {
            if (data_00257CE8->func_000C1D40(&sounds[i], &seconds[i], (int *)&values[i])) {
                Vector3 point;
                part->func_000480C0(data_0021AFD0[i]);
                func_001BAB20(&point, &data_0021AFE0[i]);
                Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (target) {
                    target->func_000651E0(0x22, &point, 0);
                }
                owner->func_000C5B50(&handles[0]);
                owner->func_000C5B50(&handles[1]);
                owner->func_000C5B50(&handles[2]);
            }
        } else {
            closed++;
        }
        if (previous[i] != values[i]) {
            owner->flags |= 0x1000000;
        }
        previous[i] = values[i];
        total += values[i];
    }
    if (total >= 2.0f) {
        owner->flags |= 0x4000000;
    }
    if (closed >= 4) {
        owner->flags |= 0x2000;
        owner->flags |= 0x20;
        owner->func_000C5AD0(1);
        done = 1;
    } else {
        func_000FEC30(owner->value_9c, &owner->position);
    }
}
