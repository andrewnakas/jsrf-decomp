// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// A std::vector of them.
struct InfoList {
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    bool func_00160050() const;

    char allocator;
    Info *first;
    Info *last;
    Info *end;
};

// Whether the vector is empty (an out-of-line copy of the inline member; 0x161920 calls it).
bool InfoList::func_00160050() const
{
    return size() == 0;
}
