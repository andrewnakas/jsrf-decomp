struct Object_00014A80 {
    char unknown_00[8];
    int type;
    char unknown_0c[0x10];
    int first;
    int second;

    int func_00014C60(int value);
};

// Says whether the type is 2 and the word at +0x1c equals a value.
int Object_00014A80::func_00014C60(int value)
{
    if (type == 2 && value == first) {
        return 1;
    }
    return 0;
}
