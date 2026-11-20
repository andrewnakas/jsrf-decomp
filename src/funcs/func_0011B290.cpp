struct Entry_0011B240 {
    int id;
    int unknown_04;
    int enabled;
    char unknown_0c[0x14];
};

struct Object_0011B240 {
    char unknown_00[0x44];
    int state;
    char unknown_48[0x14];
    int index;
    char unknown_60[0x84];
    Entry_0011B240 entries[24];

    void func_0011B290();
};

struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
extern unsigned int data_0021C450[];

// While game value 0x1ad is 0: stores the flag of the chosen entry in game value 0xd, sets game value 0x1af and
// goes to state 7.
void Object_0011B240::func_0011B290()
{
    if (data_0022FCE0->func_000127E0(0x1ad) == 0) {
        data_0022FCE0->func_000127C0(0xd, data_0021C450[entries[index].id]);
        data_0022FCE0->func_000127C0(0x1af, 1);
        state = 7;
    }
}
