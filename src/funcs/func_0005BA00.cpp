// One of the 0x54-byte entries of the list at +0x174 of the block at +0x1040.
struct Entry_0005BA00 {
    char unknown_00[0x10];
    int kind;
    char unknown_14[0x40];
};

struct Block_0005BA00 {
    char unknown_000[0x174];
    Entry_0005BA00 *entries;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x250];
    unsigned int unknown_2b0;
    int unknown_2b4;
    char unknown_2b8[0xd88];
    Block_0005BA00 *block;

    void func_0004D880();
    void func_00057F90(int index);
    int func_0005B3F0();
    void func_0005BA00();
};

// State handler 14 of the table at 0x1F9888: when func_0005B3F0 finds an entry, keeps state 0xe at +0x2b4 and hands
// it to func_00057F90; otherwise runs func_0004D880 when entry +0x2b0 (counted from 1) of the block's list is of kind
// 0xe3, and moves to state 0xf.
void Object_0004ABA0::func_0005BA00()
{
    unsigned int number = unknown_2b0;
    int index = func_0005B3F0();
    if (index >= 0) {
        unknown_2b4 = 0xe;
        func_00057F90(index);
        return;
    }
    if (number > 0 && block->entries[number - 1].kind == 0xe3)
        func_0004D880();
    state = 0xf;
}
