struct Object_0006E130 {
    int func_0006E1C0(void *data);
};

extern Object_0006E130 data_00252790;

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

// A block of 0x66c bytes, chained through its last word: the texture index at +0x64c, the texture at +0x658.
struct Owner_00036B50 {
    char unknown_000[0x64c];
    unsigned int textureIndex;
    char unknown_650[8];
    int texture;
    char unknown_65c[0xc];
    Owner_00036B50 *next;
};

// Called with a loaded block whose table follows a 0x10-byte header (the parameter is moved past it). Loads each
// chunk of the table as a texture (data_00252790's func_0006E1C0) for every owner in the list whose
// texture index is the chunk's, storing it at +0x658.
void func_00036900(Owner_00036B50 *owners, Table_00036B50 *table)
{
    table = (Table_00036B50 *)((char *)table + 0x10);
    char *data = (char *)&table->first;
    for (unsigned int i = 0; i < table->count; i++) {
        Chunk_00036B50 *chunk = (Chunk_00036B50 *)data;
        data += 0x10;
        for (Owner_00036B50 *owner = owners; owner; owner = owner->next) {
            if (owner->textureIndex == i)
                owner->texture = data_00252790.func_0006E1C0(data);
        }
        data = (char *)table + chunk->next;
    }
}
