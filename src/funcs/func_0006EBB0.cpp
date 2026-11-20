void *operator new(unsigned int size);

// Allocates a block of the size aligned to 16 bytes; the word before the aligned address keeps the block.
void *__stdcall func_0006EBB0(unsigned int size)
{
    void *result = 0;
    void *block = operator new(size + 0x14);
    if (block) {
        result = (void *)(((unsigned int)block + 0x13) & ~0xf);
        ((void **)result)[-1] = block;
    }
    return result;
}
