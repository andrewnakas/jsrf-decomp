// One of the 25 entries at 0x230DD0: the loaded file at +8, set up at +0xc.
struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    char *file;
    int busy;
};

struct Entry_00230F60 {
    void *pointer;
    int unknown_4;
};

extern int *data_001EEAF0[];
extern Entry_00230F60 data_00230F60[];
extern Entry_00230DD0 data_00230DD0[];

// A block of a loaded file: the offset of the next one (from the file) at +4.
struct Block_00036B50 {
    int unknown_00;
    unsigned int next;
};

struct Owner_00036B50;

int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
void func_00036AF0(Owner_00036B50 *owners, Block_00036B50 *block);
void func_00036B50(Owner_00036B50 *owners, Block_00036B50 *block);

// Sets up loaded file `index` (from the block at +0x10): for each list of the index's -1-terminated list at
// 0x1EEAF0, hands that list's owners (0x230F60) one block to func_00036AF0 and the next to func_00036B50, then
// marks the entry at 0x230DD0 set up. When it already is, the new file is freed instead.
void func_00036E60(int index, char **file)
{
    if (data_00230DD0[index].busy) {
        func_00145A5D(*file, 0, 0x8000);
        *file = 0;
        return;
    }
    Block_00036B50 *block = (Block_00036B50 *)(*file + 0x10);
    data_00230DD0[index].file = *file;
    for (int n = 0; data_001EEAF0[index][n] != -1; n++) {
        Owner_00036B50 *owners = (Owner_00036B50 *)data_00230F60[data_001EEAF0[index][n]].pointer;
        func_00036AF0(owners, block);
        block = (Block_00036B50 *)(*file + block->next);
        func_00036B50(owners, block);
        block = (Block_00036B50 *)(*file + block->next);
    }
    data_00230DD0[index].busy = 1;
}
