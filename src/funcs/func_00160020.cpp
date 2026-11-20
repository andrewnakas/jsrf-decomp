// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// A std::vector of them.
struct InfoList {
    char allocator;
    Info *first;
    Info *last;
    Info *end;

    unsigned int func_00160020() const;
};

// The vector's size: 0 without storage, else the number of 0x244-byte entries (an out-of-line copy of the inline
// member; 0x1612B0 calls it).
unsigned int InfoList::func_00160020() const
{
    return first == 0 ? 0 : last - first;
}
