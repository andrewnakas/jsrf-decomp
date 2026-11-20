struct Object_00039BE0 {
    char unknown_0000[0x349c];
    int count1;
    int count2;
    char unknown_34a4[0x35b0];
    int count0;

    void func_0003AEA0(int kind);
};

// Clears the counter of a kind (see func_0003A750).
void Object_00039BE0::func_0003AEA0(int kind)
{
    switch (kind) {
    case 0:
        count0 = 0;
        break;
    case 1:
        count1 = 0;
        break;
    case 2:
        count2 = 0;
        break;
    }
}
