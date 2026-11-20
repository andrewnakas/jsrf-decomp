struct Block_0003B640 {
    int unknown_00[0x20];
};

// The saved state: 0x3508 bytes from +0x4, with a second copy at +0x350c.
struct Save_0003B640 {
    char unknown_0000[0x2974];
    Block_0003B640 block;
    char unknown_29f4[0xb14];
};

extern unsigned char data_00231D40[];
extern Block_0003B640 data_002346B4;

struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    Save_0003B640 save;
    Save_0003B640 backup;

    void func_0003AED0();
    void func_0003B640();
    void func_0003B790();
};

// Copies the state out to 0x231D40 and restores it from the backup at +0x350c.
void Object_00039BE0::func_0003B790()
{
    *(Save_0003B640 *)data_00231D40 = save;
    save = backup;
}
