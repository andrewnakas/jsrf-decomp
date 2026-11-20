struct Object_000265A0 {
    char unknown_0000[0x15d4];
    int unknown_15d4;
    int unknown_15d8;
    int unknown_15dc;
    char unknown_15e0[0x18];
    int unknown_15f8;

    int func_000373C0(int value);
};

// Handler 6 of the table at 0x1EC068: clears +0x15dc, sets +0x15f8, keeps `value` at +0x15d8 and at +0x15d4 its
// group: the value itself for 0 to 4, 3 for 5 to 8, 1 for 9 to 11, 2 for 12 to 15. Returns 1.
int Object_000265A0::func_000373C0(int value)
{
    unknown_15dc = 0;
    unknown_15f8 = 1;
    unknown_15d8 = value;
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        unknown_15d4 = value;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        unknown_15d4 = 3;
        break;
    case 9:
    case 10:
    case 11:
        unknown_15d4 = 1;
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        unknown_15d4 = 2;
        break;
    }
    return 1;
}
