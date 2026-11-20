// The player (constructor func_00084200, table 0x1CCFF8): three buffers built by func_0015F2D0 from the tables at
// 0x215A90 (13 entries), 0x215B60 and 0x215C10 (11 each) of 16 bytes.
struct Object_000A1C50 {
    char unknown_00[0x70];
    void *buffer_70;
    int count_74;
    void *buffer_78;
    int count_7c;
    void *buffer_80;
    int count_84;

    void func_000A8740();
};

extern unsigned char data_00215A90[];
extern unsigned char data_00215B60[];
extern unsigned char data_00215C10[];

long __stdcall func_0015F2D0(unsigned long first, unsigned long second, unsigned long third, void **object);

// Builds the three buffers at 0x70, 0x78 and 0x80 (func_0015F2D0 with the table, 16 and the count) and keeps their
// counts at 0x74, 0x7c and 0x84.
void Object_000A1C50::func_000A8740()
{
    count_74 = 0xd;
    func_0015F2D0((unsigned long)data_00215A90, 0x10, 0xd, &buffer_70);
    count_7c = 0xb;
    func_0015F2D0((unsigned long)data_00215B60, 0x10, 0xb, &buffer_78);
    count_84 = 0xb;
    func_0015F2D0((unsigned long)data_00215C10, 0x10, 0xb, &buffer_80);
}
