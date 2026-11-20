// The 0x18-byte records of a list of the class whose table is at 0x1E19E0.
struct Record {
    char unknown[0x18];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` records of uninitialised storage at `first` with copies of `value`.
void func_00164750(Record *first, unsigned int count, const Record &value, Allocator &, Tag);

// Fills `count` records of uninitialised storage at `first` with copies of `value` (each copy only when the
// destination is not null, as placement construction does): the library's fill for the record vector, which its
// insert 0x164C20 and its member 0x1648D0 call.
void func_00164750(Record *first, unsigned int count, const Record &value, Allocator &, Tag)
{
    for (; 0 < count; --count, ++first) {
        if (first)
            *first = value;
    }
}
