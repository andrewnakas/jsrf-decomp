struct Entry;

// The lists at +0x3c8 and +0x3d8 of Object_001E1968: std::vectors of pointers.
struct EntryList {
    char allocator;
    Entry **first;
    Entry **last;
    Entry **end;

    unsigned int func_00162A00() const;
};

// The vector's size: 0 without storage, else the number of pointers (an out-of-line copy of the inline member;
// 0x162D80 calls it).
unsigned int EntryList::func_00162A00() const
{
    return first == 0 ? 0 : last - first;
}
