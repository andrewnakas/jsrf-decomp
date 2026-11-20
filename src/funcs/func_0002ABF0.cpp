extern "C" void *memset(void *destination, int value, unsigned int size);

void *operator new(unsigned int size);

// A block of a loaded file: the offset of the next one (from the file) at +4.
struct Block_00036B50 {
    int unknown_00;
    unsigned int next;
};

struct Table_00036B50;
struct Owner_00036B50;
struct Block_00036880;

void *func_00036880(void *data, Block_00036880 *block);
void func_00036900(Owner_00036B50 *owners, Table_00036B50 *table);
void func_00036970(Owner_00036B50 *owners, Table_00036B50 *table);

// An entry of the loaded pack: the offset of the next one (from the pack) at +4; a file follows at +0x10.
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
// makes a cleared list per entry of the pack, each with a cleared first owner (0x66c bytes) that func_00036880
// fills (and chains) from the entry's file; the file's next two blocks give the owners' textures (func_00036900)
// and models (func_00036970).
void func_0002ABF0(Lists_0002ACE0 *lists, Pack_0002ACE0 *pack)
{
    pack = (Pack_0002ACE0 *)((char *)pack + 0x10);
    lists->count = pack->count;
    if (lists->count > 0) {
        lists->lists = (List_0002ACE0 *)operator new(lists->count * sizeof(List_0002ACE0));
        memset(lists->lists, 0, lists->count * sizeof(List_0002ACE0));
        char *p = (char *)&pack->first;
        for (unsigned int i = 0; i < lists->count; i++) {
            Entry_0002ACE0 *current = (Entry_0002ACE0 *)p;
            p += 0x10;
            lists->lists[i].owners = (Owner_00036B50 *)operator new(0x66c);
            Owner_00036B50 *owners = lists->lists[i].owners;
            memset(owners, 0, 0x66c);
            func_00036880(p + 0x40, (Block_00036880 *)owners);
            Block_00036B50 *block = (Block_00036B50 *)(p + ((Block_00036B50 *)(p + 0x10))->next);
            func_00036900(owners, (Table_00036B50 *)block);
            func_00036970(owners, (Table_00036B50 *)(p + block->next));
            p = (char *)pack + current->next;
        }
    }
}
