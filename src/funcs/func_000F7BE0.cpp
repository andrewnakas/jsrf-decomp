// The index of a stage (area in the high word, number in the low word) in the stage list: areas 1-5 start at 0,
// 4, 9, 14 and 17 (area 4 has three stages, then 16 for the rest), any other area at 22.
int func_000F7BE0(unsigned int stage)
{
    unsigned int number = stage & 0xffff;
    int base;
    switch ((stage >> 16)) {
    case 1:
        base = 0;
        break;
    case 2:
        base = 4;
        break;
    case 3:
        base = 9;
        break;
    case 4:
        if (number < 3) {
            base = 14;
            break;
        }
        return 16;
    case 5:
        base = 17;
        break;
    default:
        base = 22;
        break;
    }
    return base + number;
}
