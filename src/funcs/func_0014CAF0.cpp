struct Info {
    unsigned long size;
    void *data;
    unsigned long value;
};

extern void *data_00264BA4;
extern Info data_00264BA8;
extern unsigned long data_00264BD4;

// Fills the record at 0x264BA8 (0x200, the data kept at 0x264BA4, the value at 0x264BD4) and returns it.
void *func_0014CAF0()
{
    data_00264BA8.size = 0x200;
    data_00264BA8.data = data_00264BA4;
    data_00264BA8.value = data_00264BD4;
    return &data_00264BA8;
}
