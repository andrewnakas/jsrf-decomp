extern int data_001EC598[];

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x704];
    int *table;

    void func_000289F0();
};

// Handler 6 of the table at 0x1EC370 (run by func_00027D40): points +0x704 at the table at 0x1EC598.
void Object_000265A0::func_000289F0()
{
    table = data_001EC598;
}
