extern int data_001EFC88[];

// The slot of a stage id (area in the high half, stage in the low half, one decimal digit each).
inline int stage_0003A2F0(unsigned int id)
{
    return data_001EFC88[(id >> 16) % 10 * 10 + (id & 0xffff) % 10];
}

struct Object_00039BE0 {
    char unknown_000[0x138];
    unsigned int bits_138[16];

    void func_0003A2F0(unsigned int id, int bit);
};

// Sets a bit in the stage's word at +0x138.
void Object_00039BE0::func_0003A2F0(unsigned int id, int bit)
{
    bits_138[stage_0003A2F0(id)] |= 1 << bit;
}
