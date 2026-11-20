/* sym: ??0Object_000BFF60@@QAE@XZ = 0x000BFF60 */
extern unsigned char data_00231D40[];
extern unsigned char data_00231E40[];
extern unsigned char data_00231F40[];

// The object func_000C04D0 allocates (0x1c bytes) and keeps in data_00257CE0.
struct Object_000BFF60 {
    Object_000BFF60();

    void *data;
    unsigned char *tables[3];
    char unknown_10[0xc];
};

// No data yet; the three 0x100-byte tables at 0x231d40, 0x231e40 and 0x231f40.
Object_000BFF60::Object_000BFF60()
{
    data = 0;
    tables[0] = data_00231D40;
    tables[1] = data_00231E40;
    tables[2] = data_00231F40;
}
