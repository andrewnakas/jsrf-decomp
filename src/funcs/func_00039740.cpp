struct Object_000265A0 {
    char unknown_0000[0x17e8];
    unsigned int soundCount;
    int result;

    int func_00039740(int unused);
};

// Handler 22 of the start table at 0x1EC068: sets +0x17ec to 2 once two sounds are queued (count at +0x17e8), else to 0.
int Object_000265A0::func_00039740(int)
{
    result = soundCount < 2 ? 0 : 2;
    return 1;
}
