struct Object_00039BE0 {
    char unknown_0000[0x349c];
    int count1;
    int count2;
    char unknown_34a4[0x35b0];
    int count0;

    int func_0003A780(int kind);
};

// The counter of a kind (see func_0003A750), or 0 for an unknown kind.
int Object_00039BE0::func_0003A780(int kind)
{
    switch (kind) {
    case 0:
        return count0;
    case 1:
        return count1;
    case 2:
        return count2;
    }
    return 0;
}
