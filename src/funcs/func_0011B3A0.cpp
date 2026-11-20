struct Entry_0011B240 {
    int id;
    int unknown_04;
    int enabled;
    char unknown_0c[0x14];
};

struct Object_0011B240 {
    char unknown_00[0x5c];
    int index;
    char unknown_60[0x84];
    Entry_0011B240 entries[24];

    void func_0011B3A0();
};

struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// While game value 0x1ad is 0: moves the index on to the next enabled entry, wrapping from 23 to 0, and
// stores it in game value 0x1ac.
void Object_0011B240::func_0011B3A0()
{
    if (data_0022FCE0->func_000127E0(0x1ad) == 0) {
        if (++index >= 24) {
            index = 0;
        }
        while (entries[index].enabled != 1) {
            if (++index >= 24) {
                index = 0;
            }
        }
        data_0022FCE0->func_000127C0(0x1ac, index);
    }
}
