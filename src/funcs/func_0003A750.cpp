struct Object_00039BE0 {
    char unknown_0000[0x349c];
    int count1;
    int count2;
    char unknown_34a4[0x35b0];
    int count0;

    void func_0003A750(int kind);
};

// Counts one event of a kind: 0 at +0x6a54, 1 at +0x349c, 2 at +0x34a0.
void Object_00039BE0::func_0003A750(int kind)
{
    switch (kind) {
    case 0:
        count0++;
        break;
    case 1:
        count1++;
        break;
    case 2:
        count2++;
        break;
    }
}
