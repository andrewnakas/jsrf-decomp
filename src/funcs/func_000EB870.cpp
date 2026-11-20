struct Object_00016200 {
    int func_0001D810(void *list, int index);
};

extern Object_00016200 data_0022FCE8;

extern unsigned char data_00231D40[];

// What func_0001D810 reads: the entries, a count and a word.
struct List_000EB870 {
    unsigned char *entries;
    int count;
    int unknown_08;
};

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    int kind;
    int handles[6];

    void func_000EB870();
};

// Fills the handles at 0x4 from the entries at data_00231D40 (func_0001D810 of data_0022FCE8): five, with the
// counts 12, 11, 6, 6 and 11, for kind 0; else two, with 11 and 21.
void Part_000EB830::func_000EB870()
{
    List_000EB870 list;
    list.entries = data_00231D40;
    list.unknown_08 = 0;
    if (kind == 0) {
        int counts[5] = {0xc, 0xb, 6, 6, 0xb};
        for (unsigned int i = 0; i < 5; i++) {
            list.count = counts[i];
            handles[i] = data_0022FCE8.func_0001D810(&list, -1);
        }
    } else {
        int counts[2] = {0xb, 0x15};
        for (unsigned int i = 0; i < 2; i++) {
            list.count = counts[i];
            handles[i] = data_0022FCE8.func_0001D810(&list, -1);
        }
    }
}
