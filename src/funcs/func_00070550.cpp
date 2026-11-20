struct Object_00070850 {
    int func_00070550(int first, int second, int mode);
};

extern int (Object_00070850::*data_0020CC7C[])(int first, int second, int flags);

// Runs the handler of a mode (table at 0x20CC7C) with the two values and no flags.
int Object_00070850::func_00070550(int first, int second, int mode)
{
    return (this->*data_0020CC7C[mode])(first, second, 0);
}
