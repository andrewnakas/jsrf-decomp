// The 0x254-byte entries of the list at +0x4e4 of Object_001E3B90.
struct Item {
    char unknown[0x254];
};

// A std::vector of them.
struct ItemList {
    char allocator;
    Item *first;
    Item *last;
    Item *end;

    unsigned int func_0016BA70() const;
};

// The vector's size: 0 without storage, else the number of 0x254-byte entries (an out-of-line copy of the inline
// member; 0x16EB90 calls it).
unsigned int ItemList::func_0016BA70() const
{
    return first == 0 ? 0 : last - first;
}
