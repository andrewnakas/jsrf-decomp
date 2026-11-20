extern int data_001EFC88[];

// The slot of a stage id (area in the high half, stage in the low half, one decimal digit each).
inline int stage_0003A2F0(unsigned int id)
{
    return data_001EFC88[(id >> 16) % 10 * 10 + (id & 0xffff) % 10];
}

extern int data_001F8C38[0x100];

struct Object_00039BE0 {
    char unknown_000[0x118];
    unsigned int flags[8];

    int func_0003A130(unsigned int id);
};

// How many of the 256 flags at +0x118 are set whose word at 0x1F8C38 holds the stage's slot.
int Object_00039BE0::func_0003A130(unsigned int id)
{
    int stage = stage_0003A2F0(id);
    int count = 0;
    for (unsigned int i = 0; i < 8; i++) {
        for (unsigned int j = 0; j < 32; j++) {
            if ((flags[i] & (1 << j)) && data_001F8C38[i * 32 + j] == stage)
                count++;
        }
    }
    return count;
}
