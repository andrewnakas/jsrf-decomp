// The child of Object_000FDDC0 whose table is at 0x1D1B20 (constructor func_000FB870); func_000FDFB0
// creates it as entry 6 of object 0x1165 and calls this on it.
struct Object_000FB530 {
    char unknown_00[0xb8];
    unsigned int limit;

    unsigned int func_000FB5B0();
};

// func_000FDFB0 compares the result with an unsigned count.
unsigned int Object_000FB530::func_000FB5B0()
{
    return limit;
}
