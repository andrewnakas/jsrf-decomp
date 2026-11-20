// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// Assigns `value` to every entry from `first` up to `last` (called by 0x1612B0).
void func_00160110(Info *first, Info *last, const Info &value)
{
    for (; first != last; ++first)
        *first = value;
}
