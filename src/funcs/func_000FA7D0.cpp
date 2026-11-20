// The child of Object_000FDDC0 whose table is at 0x1D08E0 (constructor func_000FAB60); func_000FDFB0
// creates it as entry 6 of object 0x1165 and calls this on it.
struct Object_000FAB60 {
    char unknown_00[0xbc];
    unsigned int limit;

    unsigned int func_000FA7D0();
};

// func_000FDFB0 compares the result with an unsigned count.
unsigned int Object_000FAB60::func_000FA7D0()
{
    return limit;
}
