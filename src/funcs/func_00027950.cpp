struct Motion_0006EB20;

void __stdcall func_0006EB20(Motion_0006EB20 *motion);

// One motion record of the ending's play data (0x30 bytes).
struct Item_00027950 {
    char unknown_00[0xc];
    Motion_0006EB20 *motion;
    char unknown_10[0x20];
};

// A shape of the play data: +0x2c points at its body at +0x34 once loaded.
struct Shape_00027950 {
    char unknown_00[0x2c];
    char *body;
    char unknown_30[4];
    char data[4];
};

// One entry of the play data (0x1c bytes).
struct Entry_00027950 {
    int unknown_00;
    Shape_00027950 *shapes[4];
    Item_00027950 *items;
    unsigned int count;
};

// The play data as loaded: offsets from its start in place of pointers.
struct Play_00027950 {
    unsigned int count;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    Entry_00027950 entries[1];
};

struct Object_000265A0 {
    char unknown_0000[0x17c0];
    unsigned int count;
    int unknown_17c4;
    int unknown_17c8;
    int unknown_17cc;
    int unknown_17d0;
    int unknown_17d4;
    Entry_00027950 *entries;

    void func_00027950(Play_00027950 *play);
};

// Takes the ending's play data (playdemo01.dat): copies its header to +0x17c0 and its entries to +0x17d8, and turns
// the offsets in each entry (four shapes, each pointing at its body, and the motion records, each set up by
// func_0006EB20) into pointers.
void Object_000265A0::func_00027950(Play_00027950 *play)
{
    count = play->count;
    unknown_17c4 = play->unknown_04;
    unknown_17c8 = play->unknown_08;
    unknown_17cc = play->unknown_0c;
    unknown_17d0 = play->unknown_10;
    unknown_17d4 = play->unknown_14;
    entries = play->entries;
    for (unsigned int i = 0; i < count; i++) {
        for (int k = 0; k < 4; k++) {
            if (entries[i].shapes[k]) {
                entries[i].shapes[k] = (Shape_00027950 *)((char *)play + (int)entries[i].shapes[k]);
                entries[i].shapes[k]->body = entries[i].shapes[k]->data;
            }
        }
        if (entries[i].items) {
            entries[i].items = (Item_00027950 *)((char *)play + (int)entries[i].items);
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
