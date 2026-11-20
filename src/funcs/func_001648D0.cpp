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

// A std::vector of them.
struct RecordList {
    Record *func_001648D0(Record *where, unsigned int count, const Record &value);

    Allocator allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Fills `count` places from `where` with copies of `value` with the vector's allocator (0x164750) and returns the end
// of the fill. Called by 0x164C20, the vector's insert.
Record *RecordList::func_001648D0(Record *where, unsigned int count, const Record &value)
{
    func_00164750(where, count, value, allocator, Tag());
    return where + count;
}
