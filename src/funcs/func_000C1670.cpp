struct Object_000C1670 {
    int func_000C1670(int flags);
};

// True when any of the bits 0x824 is set. func_000C3410 calls this with data_00257CE8 in ecx, which is not
// used.
int Object_000C1670::func_000C1670(int flags)
{
    if ((flags & 0x24) || (flags & 0x800)) {
        return 1;
    }
    return 0;
}
