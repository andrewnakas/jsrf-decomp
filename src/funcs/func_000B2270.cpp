/* const: 0x200000 */
/* const: 0x80000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C6B0(const Vector3 *vector);
int func_0014C7D0(float x, float z);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// One link of an entry's lists at 0x160 and 0x1a0: taken while 0 at 0x0, a direction at 0x8, the next link at 0x38.
struct Link_000B2B60 {
    int taken;
    int unknown_04;
    Vector3 direction;
    char unknown_14[0x24];
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
    char unknown_088[0x10];
    int value_098;
    char unknown_09c[0xc];
    Vector3 position;
    char unknown_0b4[0x3c];
    int yaw;
    char unknown_0f4[0x50];
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

    void func_000B2270(unsigned int index);
};

// The handler of kind-0 entries (entry 0 of data_00215D54), unless flag 0x800000 of 0x34 is set. In state 8 (or state 1
// once 0x74 and 0x78 are set; not in state 8 with flag 0x400000) the first free link of the list at 0x160 (0x1a0 with
// flag 0x200000) whose direction is longer than 0.01 moves the entry to state 3 with flag bit 30 at 0x8, clears 0x98,
// plays the entry's sound (func_000BA800) and, with flag 0x80000, turns 0xf0 a quarter past the link's heading. In
// state 3 (without flag 0x80000) the same happens for a free link unless bit 30 is already set; with no free link
// bit 30 is cleared. In state 5, once no link is free, bit 30 is cleared and the entry goes back to state 8.
void Object_000B1130::func_000B2270(unsigned int index)
{
    unsigned int options = entries[index].options;
    if (options & 0x800000) {
        return;
    }
    switch (entries[index].state) {
    case 1:
        if (!entries[index].ready || !entries[index].armed) {
            return;
        }
    case 8: {
        if (entries[index].state == 8 && (options & 0x400000)) {
            return;
        }
        Link_000B2B60 *link = (options & 0x200000) ? entries[index].otherLinks : entries[index].links;
        for (; link; link = link->next) {
            if (!link->taken) {
                if (func_0014C6B0(&link->direction) > 0.01f) {
                    entries[index].value_098 = 0;
                    entries[index].state = 3;
                    entries[index].flags |= 0x40000000;
                    if (entries[index].sound != -1) {
                        entries[index].handle = func_000BA800(entries[index].bank, 0, entries[index].sound,
                                                              &entries[index].position, entries[index].handle);
                    }
                    if (entries[index].options & 0x80000) {
                        entries[index].yaw = func_0014C7D0(link->direction.x, link->direction.z) + 0x4000;
                    }
                }
                return;
            }
        }
        break;
    }
    case 3: {
        if (options & 0x80000) {
            return;
        }
        Link_000B2B60 *link = (options & 0x200000) ? entries[index].otherLinks : entries[index].links;
        for (; link; link = link->next) {
            if (!link->taken) {
                float length = func_0014C6B0(&link->direction);
                if (!(entries[index].flags & 0x40000000) && length > 0.01f) {
                    entries[index].state = 3;
                    entries[index].value_098 = 0;
                    entries[index].flags |= 0x40000000;
                }
                return;
            }
        }
        entries[index].flags &= ~0x40000000;
        break;
    }
    case 5: {
        Link_000B2B60 *link = (options & 0x200000) ? entries[index].otherLinks : entries[index].links;
        for (; link; link = link->next) {
            if (!link->taken) {
                return;
            }
        }
        entries[index].flags &= ~0x40000000;
        entries[index].state = 8;
        break;
    }
    }
}
