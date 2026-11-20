void *operator new(unsigned int size);

// A block of 0x66c bytes, chained through its last word.
struct Block_00036880 {
    char unknown_000[0x668];
    Block_00036880 *next;
};

// Reads a list of blocks from loaded data (a word, the count, then each block after a word of its own) into the chain
// that starts at `block`, allocating each block after the first. Returns the end of the data read.
static inline unsigned int read(char *&p)
{
    unsigned int value = *(unsigned int *)p;
    p += 4;
    return value;
}

void *func_00036880(void *data, Block_00036880 *block)
{
    char *p = (char *)data;
    read(p);
    unsigned int count = read(p);
    for (unsigned int i = 0; i < count; i++) {
        p += 4;
        *block = *(Block_00036880 *)p;
        p += sizeof(Block_00036880);
        if (i < count - 1) {
            block->next = (Block_00036880 *)operator new(sizeof(Block_00036880));
            block = block->next;
        }
    }
    return p;
}
