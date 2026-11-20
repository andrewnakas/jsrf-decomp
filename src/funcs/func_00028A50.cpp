extern int data_001EC5F0[];

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x704];
    int *table;

    void func_00028A50();
};

// Handler 15 of the table at 0x1EC370 (run by func_00027D40): points +0x704 at the table at 0x1EC5F0.
void Object_000265A0::func_00028A50()
{
    table = data_001EC5F0;
}
