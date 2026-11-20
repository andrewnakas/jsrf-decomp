/* const: 0x200000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C6B0(const Vector3 *vector);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// One link of an entry's lists at 0x160 and 0x1a0: taken while 0 at 0x0, a direction at 0x8, the next link at 0x38.
struct Link_000B2B60 {
    int taken;
    int unknown_04;
    Vector3 direction;
    char unknown_14[0x18];
    float side;
    int unknown_30;
    float front;
    Link_000B2B60 *next;
};

// One of the node's entries (0x1e0 bytes).
struct Entry_000B2B60 {
    int used;
    int kind;
    unsigned int flags;
    char unknown_00c[0x28];
    unsigned int options;
    char unknown_038[0x2c];
    int sound;
    char unknown_068[0xc];
    int ready;
    int armed;
    char unknown_07c[4];
    int bank;
    int handle;
    char unknown_088[8];
    int value_090;
    int value_094;
    int value_098;
    int value_09c;
    char unknown_0a0[8];
    Vector3 position;
    char unknown_0b4[4];
    int angle;
    char unknown_0bc[0x88];
    int state;
    char unknown_148[0x18];
    Link_000B2B60 *links;
    char unknown_164[0x3c];
    Link_000B2B60 *otherLinks;
    char unknown_1a4[0x3c];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD838).
struct Object_000B1130 {
    char unknown_000[0x44];
    Entry_000B2B60 *entries;
    unsigned int count;

    void func_000B2B60(unsigned int index);
};

// The second handler of kind-2 entries (data_00215D54): in state 8 (or state 1 once 0x74 and 0x78 are set), unless
// flag 0x800000 (or 0x400000 in state 8) of 0x34 is set, takes the first link of the list at 0x160 (0x1a0 with flag
// 0x200000) that is free; if its direction is longer than 0.01, picks 0x94 or 0x9c for 0x90 by the side the entry's
// angle (0xb8) turns (1, 0, 0) to against the link, clears 0x98, moves to state 3, sets flag bit 30 at 0x8 and plays
// the entry's sound at 0x64 (func_000BA800) at its position.
void Object_000B1130::func_000B2B60(unsigned int index)
{
    Vector3 point;
    point.x = 1.0f;
    point.y = 0.0f;
    point.z = 0.0f;
    switch (entries[index].state) {
    case 1:
        if (!entries[index].ready || !entries[index].armed) {
            return;
        }
    case 8: {
        if (entries[index].state == 8 && (entries[index].options & 0x400000)) {
            return;
        }
        if (entries[index].options & 0x800000) {
            return;
        }
        Link_000B2B60 *link = (entries[index].options & 0x200000) ? entries[index].otherLinks : entries[index].links;
        for (; link; link = link->next) {
            if (!link->taken) {
                if (func_0014C6B0(&link->direction) > 0.01f) {
                    func_001BAA00();
                    func_001BB330(entries[index].angle);
                    func_001BAB20(&point, &point);
                    if (point.z * link->side - point.x * link->front < 0.0f) {
                        entries[index].value_090 = entries[index].value_094;
                    } else {
                        entries[index].value_090 = entries[index].value_09c;
                    }
                    func_001BAA50();
                    entries[index].value_098 = 0;
                    entries[index].state = 3;
                    entries[index].flags |= 0x40000000;
                    if (entries[index].sound != -1) {
                        entries[index].handle = func_000BA800(entries[index].bank, 0, entries[index].sound,
                                                              &entries[index].position, entries[index].handle);
                    }
                }
                return;
            }
        }
        break;
    }
    }
}
