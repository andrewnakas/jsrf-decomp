extern int data_001EFC88[];

// The slot of a stage id (area in the high half, stage in the low half, one decimal digit each).
inline int stage_0003A2F0(unsigned int id)
{
    return data_001EFC88[(id >> 16) % 10 * 10 + (id & 0xffff) % 10];
}

struct Object_00039BE0 {
    char unknown_000[0x178];
    int values_178[16][0x50][2];

    void func_0003A400(unsigned int id, unsigned int entry, int field, int value);
};

// Fills one value of an entry of the stage's table at +0x178 with ten copies of a 3-bit value.
void Object_00039BE0::func_0003A400(unsigned int id, unsigned int entry, int field, int value)
{
    if (entry != -1) {
        int bits = value & 7;
        int fill = bits;
        for (int i = 0; i < 9; i++) {
            fill = (fill << 3) | bits;
        }
        values_178[stage_0003A2F0(id)][entry][field] = fill;
    }
}
