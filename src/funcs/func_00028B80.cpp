extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

// A 0x1b0-byte block of the table at +0xc0c; its first word is its index.
struct Block_00028B80 {
    int index;
    char unknown_004[0x1ac];
};

struct Object_000265A0 {
    char unknown_0000[0x748];
    int unknown_748;
    int unknown_74c;
    char unknown_0750[0x4b4];
    int index;
    int unknown_c08;
    Block_00028B80 *blocks[1];

    int func_00028B80(int index);
};

// Handler 9 of the table at 0x1EC068: keeps `index` at +0xc04; with block `index` of the table at +0xc0c present,
// 4 into +0x748; otherwise a new cleared block for it (0 when that fails), 1 into +0xc08, func_00043700 of 0x1FC724
// at +0x74c and 0 into +0x748. Returns 1.
int Object_000265A0::func_00028B80(int index)
{
    this->index = index;
    if (blocks[index]) {
        unknown_748 = 4;
        return 1;
    }
    Block_00028B80 *block = new Block_00028B80;
    blocks[index] = block;
    if (!block)
        return 0;
    memset(block, 0, sizeof(Block_00028B80));
    blocks[index]->index = index;
    unknown_c08 = 1;
    unknown_74c = data_001FC724.func_00043700();
    unknown_748 = 0;
    return 1;
}
