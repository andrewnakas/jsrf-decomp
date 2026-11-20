// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0): its slot 16 (func_000FDDC0) and slot 1
// (func_000FDA20) use the flags at 0x80 too.
struct Object_000FDDC0 {
    char unknown_00[0x80];
    unsigned int flags;

    void func_000FDDE0();
};

// Sets bit 26 of the flags at 0x80.
void Object_000FDDC0::func_000FDDE0()
{
    flags |= 0x4000000;
}
