struct Header_0006EA40;

void __stdcall func_0006EA40(Header_0006EA40 *header);

struct Motion_0005F060;

// An entry of a set (0xc bytes): its offset from the set, the offset of the next entry and whether it is there.
struct Item_0006A300 {
    int offset;
    int next;
    int present;
};

// A set of a pack: the count of its entries at +0x4, the first entry at +0x10.
struct Set_0006A300 {
    char unknown_00[4];
    unsigned int count;
    char unknown_08[8];
    Item_0006A300 first;
};

// A pack of motion sets: their count at +0x4 and the first set's entry at +0x10.
struct Pack_0006A300 {
    char unknown_00[4];
    unsigned int count;
    char unknown_08[8];
    Item_0006A300 first;
};

struct Object_0006A720 {
    char unknown_000[0x9bc];
    Motion_0005F060 *motions[10][5];
    float times[10][5];
    Pack_0006A300 *pack;

    void func_0006A300(Pack_0006A300 *pack);
};

// Keeps the pack at +0xb4c and takes up to five motions from each of its sets: each present entry is relocated
// (func_0006EA40) and becomes motions[set][entry].
void Object_0006A720::func_0006A300(Pack_0006A300 *pack)
{
    this->pack = pack;
    Item_0006A300 *group = &pack->first;
    for (unsigned int i = 0; i < pack->count; i++) {
        if (group->present) {
            Set_0006A300 *set = (Set_0006A300 *)((char *)pack + group->offset);
            Item_0006A300 *item = &set->first;
            for (unsigned int j = 0; j < set->count && j < 5; j++) {
                if (item->present) {
                    Header_0006EA40 *header = (Header_0006EA40 *)((char *)set + item->offset);
                    func_0006EA40(header);
                    motions[i][j] = (Motion_0005F060 *)header;
                }
                item = (Item_0006A300 *)((char *)set + item->next);
            }
        }
        group = (Item_0006A300 *)((char *)pack + group->next);
    }
}
