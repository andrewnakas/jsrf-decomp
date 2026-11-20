struct Block_0003EE20 {
    char unknown_00[0x9c];
    unsigned int first;
    char unknown_a0[0xc];
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
};

// Turns the four offsets of a loaded block (+0x9c, +0xac, +0xb0, +0xb4) into pointers, each only when it is set.
void func_0003EE20(Block_0003EE20 *block)
{
    if (block->first > 0)
        block->first += (unsigned int)block;
    if (block->second > 0)
        block->second += (unsigned int)block;
    if (block->third > 0)
        block->third += (unsigned int)block;
    if (block->fourth > 0)
        block->fourth += (unsigned int)block;
}
