// The saved state: 0x3508 bytes from +0x4, with a second copy at +0x350c.
struct Save_0003B640 {
    int words[0xd42];
};

extern unsigned char data_00231D40[];

struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    Save_0003B640 save;
    Save_0003B640 backup;

    void func_0003B6A0();
};

// Copies the state out to 0x231D40 and restores it from the backup at +0x350c, keeping words 0x25 to 0x34 and word 3
// of the state it copied out.
void Object_00039BE0::func_0003B6A0()
{
    *(Save_0003B640 *)data_00231D40 = save;
    save = backup;
    for (unsigned int i = 0x25; i < 0x35; i++) {
        save.words[i] = ((Save_0003B640 *)data_00231D40)->words[i];
    }
    save.words[3] = ((Save_0003B640 *)data_00231D40)->words[3];
}
