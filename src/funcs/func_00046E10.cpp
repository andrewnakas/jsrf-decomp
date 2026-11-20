// The memory-unit manager at 0x1F97A8.
struct Object_00047110 {
    int func_00046C40(char drive, const char *name);
    int func_00046E10();
};

// Called by func_0006F1B0: func_00046C40 for drive 0x55 ('U') and "JSRFDATA.SAV".
int Object_00047110::func_00046E10()
{
    return func_00046C40(0x55, "JSRFDATA.SAV");
}
