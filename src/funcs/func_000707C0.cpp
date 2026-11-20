// The class of the tables at +0xa0 and records at +0xe8 (40 bytes each).
struct Object_00070850 {
    int func_000707C0(int value);
};

// Maps 0 to 23 to 3 2 3 4 1 2 3 4 5 0 1 2 4 5 6 1 2 3 4 5 2 3 4 3; anything else to -1.
int Object_00070850::func_000707C0(int value)
{
    switch (value) {
    case 9:
        return 0;
    case 4:
    case 10:
    case 15:
        return 1;
    case 1:
    case 5:
    case 11:
    case 16:
    case 20:
        return 2;
    case 0:
    case 2:
    case 6:
    case 17:
    case 21:
    case 23:
        return 3;
    case 3:
    case 7:
    case 12:
    case 18:
    case 22:
        return 4;
    case 8:
    case 13:
    case 19:
        return 5;
    case 14:
        return 6;
    }
    return -1;
}
