struct Object_000265A0 {
    char unknown_0000[0x17a0];
    int unknown_17a0[5];
    int unknown_17b4;
    int unknown_17b8;

    int func_00027860(int argument);
};

// Handler 21 of the table at 0x1EC068: clears the words at +0x17a0 to +0x17b8.
int Object_000265A0::func_00027860(int argument)
{
    unknown_17b8 = 0;
    for (int i = 0; i < 5; i++) {
        unknown_17a0[i] = 0;
    }
    unknown_17b4 = 0;
    return 1;
}
