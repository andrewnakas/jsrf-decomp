extern int data_001FBA68[];

struct Block_00067A20 {
    char unknown_00[0x50];
};

struct Object_00067380 {
    char unknown_000[0x34c];
    Block_00067A20 blocks[1];

    Block_00067A20 *func_00067A20(int index);
};

// The block (0x50 bytes, from +0x34c) the table at 0x1FBA68 gives for an index.
Block_00067A20 *Object_00067380::func_00067A20(int index)
{
    return &blocks[data_001FBA68[index]];
}
