struct Object_00120420 {
    char unknown_000[0x8a4];
    int ids[3];
    char unknown_8b0[0x2a0];
    void *interfaces[3];

    void func_00130780();
};

extern int data_0025C314;
extern int data_0025C318;
extern int data_0025C31C;
extern int data_0025C320;

// Sets the three ids at +0x8a4 to -1 and clears the three pointers at +0xb50 and four globals.
void Object_00120420::func_00130780()
{
    ids[0] = -1;
    ids[1] = -1;
    ids[2] = -1;
    interfaces[0] = 0;
    interfaces[1] = 0;
    interfaces[2] = 0;
    data_0025C314 = 0;
    data_0025C318 = 0;
    data_0025C31C = 0;
    data_0025C320 = 0;
}
