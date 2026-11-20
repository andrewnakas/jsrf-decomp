struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_00214F40[];

void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third);

// The object whose id the player keeps at 0xc98.
struct Partner_0009C210 {
    char unknown_000[0x23c];
    unsigned int id;
};

struct Entry_002104A0 {
    char unknown_00[0x28];
    int pair;
    char unknown_2c[4];
};

// A pair of keys of the table at 0x5c.
struct Pair_0009C0C0 {
    int first;
    int second;
};

struct Object_000A1C50 {
    char unknown_000[0x5c];
    Pair_0009C0C0 *pairs;
    char unknown_060[0xc38];
    int partnerId;
    char unknown_c9c[0x1d4];
    int value_e70;

    Entry_002104A0 *func_000A0120(int index);
    void func_0009BF70(int index, int flag);
};

// For entry `index` (func_000A0120) with a pair: the pair's second key while 0xe70 is set, else its first, looked up
// in data_00214F40 and passed with the id at 0x23c of the object at 0xc98, when it exists, to func_00106E50 (kind 0,
// then the flag, 0).
void Object_000A1C50::func_0009BF70(int index, int flag)
{
    int pair = func_000A0120(index)->pair;
    if (pair != -1) {
        int value;
        if (value_e70) {
            value = data_00214F40[pairs[pair].second];
        } else {
            value = data_00214F40[pairs[pair].first];
        }
        Partner_0009C210 *partner = (Partner_0009C210 *)data_0022FCE0->func_000128C0(partnerId);
        if (partner) {
            func_00106E50(partner->id, 0, value, flag, 0);
        }
    }
}
