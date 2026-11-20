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

struct Target_00036AF0 {
    char unknown_00[0x60];
    void *data;
};

struct Owner_00036B50 {
    char unknown_000[0x650];
    unsigned int index;
    char unknown_654[8];
    Target_00036AF0 *target;
    char unknown_660[8];
    Owner_00036B50 *next;
};

// Hands each chunk's data to +0x60 of the object at +0x65c of every owner in the list whose index is the chunk's.
void func_00036AF0(Owner_00036B50 *owners, Block_00036B50 *block)
{
    Table_00036B50 *table = &block->table;
    char *data = (char *)&table->first;
    for (unsigned int i = 0; i < table->count; i++) {
        Chunk_00036B50 *chunk = (Chunk_00036B50 *)data;
        data += 0x10;
        for (Owner_00036B50 *owner = owners; owner; owner = owner->next) {
            if (owner->index == i)
                owner->target->data = data;
        }
        data = (char *)table + chunk->next;
    }
}
