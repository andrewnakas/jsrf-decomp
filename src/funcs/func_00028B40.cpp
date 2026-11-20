extern int data_001EC644[];

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x704];
    int *table;

    void func_00028B40();
};

// Handler 8 of the table at 0x1EC370 (run by func_00027D40): points +0x704 at the table at 0x1EC644.
void Object_000265A0::func_00028B40()
{
    table = data_001EC644;
}
