struct Object_00065730 {
    int func_00066FF0();
};

extern Object_00065730 data_001FB8E8;

struct Object_00014A80 {
    char unknown_00[8];
    int type;
    char unknown_0c[0x10];
    int first;
    int second;
    char unknown_24[0x34];
    int count;

    int func_00014CA0(int *first, int *second);
};

// As func_00014C30, but only once the count at +0x58 has reached func_00066FF0 of the list at 0x1FB8E8.
int Object_00014A80::func_00014CA0(int *first, int *second)
{
    if (type == 2 && count >= data_001FB8E8.func_00066FF0()) {
        *first = this->first;
        *second = this->second;
        return 1;
    }
    return 0;
}
