struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The same object seen through func_000B4150's declaration.
struct Object_000B4150 {
    int func_000B4150(int first, int second, int third, int fourth);
};

// The class whose table is at 0x1CD8C8 (constructor func_000B4330, which calls this; func_000BAD80 finds it by id):
// up to ten child ids at 0x8c, counted at 0xbc, and ten keys at 0xec with their values at 0x114.
struct Object_000B40F0 {
    char unknown_00[0x8c];
    int ids[10];
    char unknown_b4[8];
    int count;
    char unknown_c0[0x2c];
    int keys[10];
    int values[10];

    int freeSlot()
    {
        for (int i = 0; i < 10; i++) {
            if (ids[i] == 0) {
                return i;
            }
        }
        return -1;
    }
    void func_000B40F0();
    void func_000B4290(int clear);
};

// Optionally takes the children out first (func_000B40F0); then for every key at 0xec other than -1 with a free child
// slot, makes a child (func_000B4150 with the key, its value and 1.0) whose id, the first free one in [0x10F9, 0x115D],
// goes into the slot and the count.
void Object_000B40F0::func_000B4290(int clear)
{
    if (clear) {
        func_000B40F0();
    }
    for (int k = 0; k < 10; k++) {
        if (keys[k] != -1) {
            int slot = freeSlot();
            if (slot != -1) {
                int id = data_0022FCE0->func_000128E0(0x10f9, 0x115d);
                ((Object_000B4150 *)this)->func_000B4150(0, keys[k], values[k], 0x3f800000);
                ids[slot] = id;
                count++;
            }
        }
    }
}
