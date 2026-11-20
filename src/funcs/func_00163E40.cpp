// The 0x18-byte entries of a list in Object_001E19E0.
struct Record {
    unsigned long words[6];
};

// Stores the value in every entry from `first` up to `last` (the library's fill; 0x164C20 calls it).
void func_00163E40(Record *first, Record *last, const Record &value)
{
    for (; first != last; ++first)
        *first = value;
}
