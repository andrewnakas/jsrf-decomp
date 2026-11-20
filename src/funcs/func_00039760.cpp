struct Object_000265A0 {
    char unknown_0000[0x17e8];
    unsigned int soundCount;

    int func_00039760(int unused);
};

// Handler 22 of the poll table at 0x1EC178: 1 once two sounds are queued (count at +0x17e8).
int Object_000265A0::func_00039760(int)
{
    return soundCount >= 2;
}
