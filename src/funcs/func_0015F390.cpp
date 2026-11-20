struct Storage {
    char unknown_00[0x44];
};

extern int data_00265154;
long __stdcall func_0015F0F0(Storage *storage, void *data, unsigned long size, unsigned long count);

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 {
    virtual long __stdcall func_0015F390(void *data, unsigned long size, unsigned long count);  // slot 3

    Storage storage;
};

// Sets up the storage at +4 (func_0015F0F0) and counts one more live object at 0x265154 when that succeeds.
long __stdcall Object_001E1798::func_0015F390(void *data, unsigned long size, unsigned long count)
{
    long result = func_0015F0F0(&storage, data, size, count);
    if (result >= 0)
        data_00265154++;
    return result;
}
