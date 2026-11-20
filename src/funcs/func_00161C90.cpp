// The class whose table is at 0x1E1968.
struct Object_001E1968;

// Gives the count for the kind of object, the low byte of the word at +0x274 of the class whose table is at 0x1E1968
// (its slot 0x1638D0 passes the object, that word and +0x3c4): 5 for kind 0x12, 6 for every other. Always S_OK.
long __stdcall func_00161C90(Object_001E1968 *self, unsigned long kind, unsigned int *count)
{
    switch ((unsigned char)kind) {
    case 0x12:
        *count = 5;
        return 0;
    case 0x13:
        *count = 6;
        return 0;
    default:
        *count = 6;
        return 0;
    }
}
