struct Record_00077BF0 {
    int unknown_00;
    char unknown_04[8];
    int unknown_0c;
    char unknown_10[0x10];
};

struct Object_00077BF0 {
    char unknown_00[0xa4];
    Record_00077BF0 *lists[1];

    int func_00077C10(int list, int index);
};

// The field at +0xc of one 32-byte record of one of the lists at +0xa4.
int Object_00077BF0::func_00077C10(int list, int index)
{
    return lists[list][index].unknown_0c;
}
