// The 0x18-byte entries of a list in Object_001E19E0 (0x164C20 fills them).
struct Record {
    char unknown[0x18];
};

// A std::vector of them.
struct RecordList {
    char allocator;
    Record *first;
    Record *last;
    Record *end;

    unsigned int func_00163D80() const;
};

// The vector's size: 0 without storage, else the number of 0x18-byte entries (an out-of-line copy of the inline
// member; 0x164C20 calls it).
unsigned int RecordList::func_00163D80() const
{
    return first == 0 ? 0 : last - first;
}
