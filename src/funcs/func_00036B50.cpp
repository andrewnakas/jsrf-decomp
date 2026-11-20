struct Header_0006EA40;

void __stdcall func_0006EA40(Header_0006EA40 *header);

// A chunk of a loaded table: the offset of the next one (from the table) at +4, its data at +0x10.
struct Chunk_00036B50 {
    int unknown_00;
    unsigned int next;
    char unknown_08[8];
    char data[1];
};

struct Table_00036B50 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Chunk_00036B50 first;
};

struct Block_00036B50 {
    char unknown_00[0x10];
    Table_00036B50 table;
};

struct Owner_00036B50 {
    char unknown_000[0x650];
    unsigned int index;
    char unknown_654[0xc];
    Header_0006EA40 *data;
    char unknown_664[4];
    Owner_00036B50 *next;
};

// Relocates each chunk's data (func_0006EA40) and hands it to every owner in the list whose index is the chunk's.
void func_00036B50(Owner_00036B50 *owners, Block_00036B50 *block)
{
    Table_00036B50 *table = &block->table;
    char *data = (char *)&table->first;
    for (unsigned int i = 0; i < table->count; i++) {
        Chunk_00036B50 *chunk = (Chunk_00036B50 *)data;
        data += 0x10;
        func_0006EA40((Header_0006EA40 *)data);
        for (Owner_00036B50 *owner = owners; owner; owner = owner->next) {
            if (owner->index == i)
                owner->data = (Header_0006EA40 *)data;
        }
        data = (char *)table + chunk->next;
    }
}
