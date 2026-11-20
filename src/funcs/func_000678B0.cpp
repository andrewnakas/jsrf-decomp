struct Object_00047110 {
    int func_00046E20(int id, int value, const char *name);
};

extern Object_00047110 data_001F97A8;

struct Object_00067980 {
    char unknown_000[0x678];
    int unknown_678;

    int func_000678B0();
};

// Asks the object at 0x1F97A8 (func_00046E20, 0x55) about "JSRFDATA.SAV" with the word at +0x678; says whether it
// answered.
int Object_00067980::func_000678B0()
{
    return data_001F97A8.func_00046E20(0x55, unknown_678, "JSRFDATA.SAV") != 0;
}
