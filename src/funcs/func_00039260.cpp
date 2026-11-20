struct Motion_0006EB20;

void __stdcall func_0006EB20(Motion_0006EB20 *motion);

// One motion record of the title's play data (0x30 bytes).
struct Item_00039260 {
    char unknown_00[0xc];
    Motion_0006EB20 *motion;
    char unknown_10[0x20];
};

// A shape of the play data: +0x2c points at its body at +0x34 once loaded.
struct Shape_00039260 {
    char unknown_00[0x2c];
    char *body;
    char unknown_30[4];
    char data[4];
};

// One entry of the play data (0x1c bytes).
struct Entry_00039260 {
    int unknown_00;
    Shape_00039260 *shapes[4];
    Item_00039260 *items;
    unsigned int count;
};

// The play data as loaded: offsets from its start in place of pointers.
struct Play_00039260 {
    unsigned int count;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    Entry_00039260 entries[1];
};

struct Object_000265A0 {
    char unknown_0000[0x177c];
    unsigned int count;
    int unknown_1780;
    int unknown_1784;
    int unknown_1788;
    int unknown_178c;
    int unknown_1790;
    Entry_00039260 *entries;

    void func_00039260(Play_00039260 *play);
};

// Takes the title's play data (playdemo%02d.dat): copies its header to +0x177c and its entries to +0x1794, and turns
// the offsets in each entry (four shapes, each pointing at its body, and the motion records, each set up by
// func_0006EB20) into pointers.
void Object_000265A0::func_00039260(Play_00039260 *play)
{
    count = play->count;
    unknown_1780 = play->unknown_04;
    unknown_1784 = play->unknown_08;
    unknown_1788 = play->unknown_0c;
    unknown_178c = play->unknown_10;
    unknown_1790 = play->unknown_14;
    entries = play->entries;
    for (unsigned int i = 0; i < count; i++) {
        for (int k = 0; k < 4; k++) {
            if (entries[i].shapes[k]) {
                entries[i].shapes[k] = (Shape_00039260 *)((char *)play + (int)entries[i].shapes[k]);
                entries[i].shapes[k]->body = entries[i].shapes[k]->data;
            }
        }
        if (entries[i].items) {
            entries[i].items = (Item_00039260 *)((char *)play + (int)entries[i].items);
            for (unsigned int j = 0; j < entries[i].count; j++) {
                if (entries[i].items[j].motion) {
                    entries[i].items[j].motion =
                        (Motion_0006EB20 *)((char *)play + (int)entries[i].items[j].motion);
                    func_0006EB20(entries[i].items[j].motion);
                }
            }
        }
    }
}
