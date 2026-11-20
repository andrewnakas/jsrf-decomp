struct Object_00014A80 {
    char unknown_00[8];
    int type;
    char unknown_0c[0x10];
    int first;
    int second;

    int func_00014C30(int *first, int *second);
};

// For type 2, copies the two words at +0x1c and +0x20 out and returns 1; otherwise returns 0.
int Object_00014A80::func_00014C30(int *first, int *second)
{
    if (type == 2) {
        *first = this->first;
        *second = this->second;
        return 1;
    }
    return 0;
}
