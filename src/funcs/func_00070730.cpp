// The class of the tables at +0xa0 and records at +0xe8 (40 bytes each).
struct Object_00070850 {
    int func_00070730(int value);
};

// Sorts 0 to 23 into seven bands: 0, 1-3, 4-8, 9-14, 15-19, 20-22 and 23 give 0 to 6; anything else -1.
int Object_00070850::func_00070730(int value)
{
    switch (value) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return 2;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 3;
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        return 4;
    case 20:
    case 21:
    case 22:
        return 5;
    case 23:
        return 6;
    }
    return -1;
}
