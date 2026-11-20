struct Object_000265A0 {
    char unknown_0000[0x17e0];
    void *values[2];
    unsigned int count;

    void *func_00039770(int index, int unused1, int unused2);
};

// Handler in the table at 0x1EC200 (called with three arguments at 0x25732): one of the values at +0x17e0 once the count at +0x17e8 has reached 2.
void *Object_000265A0::func_00039770(int index, int, int)
{
    if (count >= 2) {
        return values[index];
    }
    return 0;
}
