/* const: 0x200100 */
/* sym: ??0Object_000ACFB0@@QAE@PAUNode@@HIPAUParams_000AD4B0@@H@Z = 0x000AD4B0 */
struct Node;

void *__cdecl operator new(unsigned int size);

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

void *func_00025700(unsigned int index, int first, int second, int third);

// A 0x18-byte entry of bank 7, table 7: flags first and a word at 0x14 that the caller sets.
struct Params_000AD4B0 {
    unsigned int flags;
    int unknown_04[4];
    int value_14;
};

// The child class made here (constructor func_000AD4B0, 0x21c bytes; table 0x1CD6E8).
struct Object_000ACFB0 {
    Object_000ACFB0(Node *owner, int id, unsigned int flags, Params_000AD4B0 *entry, int value);

    char unknown_000[0x21c];
};

// The class whose table is at 0x1CD8C8 (Object_000B40F0 elsewhere): up to ten child ids at 0x8c, counted at 0xbc.
struct Object_000B4150 {
    char unknown_00[0x44];
    int bank;
    char unknown_48[0x44];
    int ids[10];
    char unknown_b4[8];
    unsigned int count;

    int freeSlot()
    {
        for (int i = 0; i < 10; i++) {
            if (ids[i] == 0) {
                return i;
            }
        }
        return -1;
    }
    int func_000B4150(int first, int second, int third, int fourth);
};

// With a free child slot (and at most ten children), makes a child (func_000AD4B0) with the first free id in
// [0x10F9, 0x115D] from entry `second & 0x3ff` of bank 7, table 7, its flags or'ed with `first` and `fourth` at 0x14,
// passing `third`; keeps the id in the slot and the count and returns it, else 0.
int Object_000B4150::func_000B4150(int first, int second, int third, int fourth)
{
    if (count > 10) {
        return 0;
    }
    int slot = freeSlot();
    if (slot == -1) {
        return 0;
    }
    int index = second & 0x3ff;
    Params_000AD4B0 *entries = (Params_000AD4B0 *)func_00025700(7, bank, 7, 1);
    Params_000AD4B0 entry = entries[index];
    entry.flags |= first;
    entry.value_14 = fourth;
    int id = data_0022FCE0->func_000128E0(0x10f9, 0x115d);
    new Object_000ACFB0((Node *)this, id, 0x200100, &entry, third);
    ids[slot] = id;
    count++;
    return id;
}
