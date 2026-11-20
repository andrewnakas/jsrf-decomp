// Gives the size for a kind of object, the low byte of the word (the slot 0x1655E0 of the class whose table is at
// 0x1E2008 passes its field +0x924 and the address of +0x918): 0x1C for kind 0x12, 0x400 for kind 0x13 and 0xB0 for
// every other. Always S_OK.
long __stdcall func_001655A0(unsigned long kind, unsigned int *size)
{
    switch ((unsigned char)kind) {
    case 0x12:
        *size = 0x1C;
        return 0;
    case 0x13:
        *size = 0x400;
        return 0;
    default:
        *size = 0xB0;
        return 0;
    }
}
