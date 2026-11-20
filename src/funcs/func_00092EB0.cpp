// The player object: this handler sits next to func_00092F60 and func_00092FC0 in the tables at 0x20E520 and
// 0x20E610.
struct Object_000A1C50 {
    char unknown_000[0xe58];
    int phase;

    int func_00092EB0(int index, int unused);
};

extern int (Object_000A1C50::*data_0020E11C[])();

// Sets the phase and runs the handler the table holds for the index; the same shape as func_00092E90.
int Object_000A1C50::func_00092EB0(int index, int)
{
    phase = 3;
    return (this->*data_0020E11C[index])();
}
