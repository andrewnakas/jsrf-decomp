extern int data_001EFC88[];

// The slot of a stage id (area in the high half, stage in the low half, one decimal digit each).
inline int stage_0003A2F0(unsigned int id)
{
    return data_001EFC88[(id >> 16) % 10 * 10 + (id & 0xffff) % 10];
}

struct Object_00039BE0 {
    char unknown_000[0x178];
    int values_178[16][0x50][2];

    int func_0003A340(unsigned int id, unsigned int entry, int field);
    void func_0003A3A0(unsigned int id, unsigned int entry, int field, int value);
};

// Sets one of the two values of an entry of the stage's table at +0x178.
void Object_00039BE0::func_0003A3A0(unsigned int id, unsigned int entry, int field, int value)
{
    if (entry != -1 && entry < 0x50) {
        values_178[stage_0003A2F0(id)][entry][field] = value;
    }
}
