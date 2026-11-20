// A block of a loaded file: the offset of the next one (from the file) at +4.
struct Block_00036B50 {
    int unknown_00;
    unsigned int next;
};

struct Owner_00036B50;

void func_00036AF0(Owner_00036B50 *owners, Block_00036B50 *block);
void func_00036B50(Owner_00036B50 *owners, Block_00036B50 *block);

// An entry of the loaded pack: the offset of the next one (from the pack) at +4; a file follows at +0x10, its first
// block at +0x10 of that and its second at the offset the first gives.
struct Entry_0002ACE0 {
    int unknown_00;
    unsigned int next;
    char unknown_08[8];
};

struct Pack_0002ACE0 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_0002ACE0 first;
};

// One list of owners (8 bytes).
struct List_0002ACE0 {
    Owner_00036B50 *owners;
    int unknown_04;
};

// What func_0002AD60 passes: the number of lists at +0x1a8 and the lists at +0x1ac.
struct Lists_0002ACE0 {
    char unknown_000[0x1a8];
    unsigned int count;
    List_0002ACE0 *lists;
};

// Called by func_0002AD60 with a loaded file whose pack follows a 0x10-byte header (the parameter is moved past it):
// takes the list count from the pack and hands each list's owners the two blocks of its entry's file (func_00036AF0,
// then func_00036B50).
void func_0002ACE0(Lists_0002ACE0 *lists, Pack_0002ACE0 *pack)
{
    pack = (Pack_0002ACE0 *)((char *)pack + 0x10);
    lists->count = pack->count;
    if (lists->count > 0) {
        char *p = (char *)&pack->first;
        for (unsigned int i = 0; i < lists->count; i++) {
            Owner_00036B50 *owners = lists->lists[i].owners;
            Entry_0002ACE0 *current = (Entry_0002ACE0 *)p;
            p += 0x10;
            Block_00036B50 *block = (Block_00036B50 *)(p + 0x10);
            func_00036AF0(owners, block);
            func_00036B50(owners, (Block_00036B50 *)(p + block->next));
            p = (char *)pack + current->next;
        }
    }
}
