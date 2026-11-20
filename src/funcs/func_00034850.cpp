struct Lists_00034850 {
    void **first;
    char unknown_04[0xc];
    void **second;
    char unknown_14[4];
    void **third;
};

struct Object_000265A0 {
    char unknown_0000[0x15fc];
    Lists_00034850 *lists;

    void *func_00034850(int unused, int kind, int index);
};

// Handler 10 of the table at 0x1EC200: pointer `index` of the first (+0x0), second (+0x10) or third (+0x18) list of the
// block at +0x15fc for kinds 0 to 2; 0 otherwise or without the block.
void *Object_000265A0::func_00034850(int, int kind, int index)
{
    Lists_00034850 *lists = this->lists;
    if (lists) {
        switch (kind) {
        case 0:
            return lists->first[index];
        case 1:
            return lists->second[index];
        case 2:
            return lists->third[index];
        }
    }
    return 0;
}
