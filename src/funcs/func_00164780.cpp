// The 0x18-byte records of a list of the class whose table is at 0x1E19E0.
struct Record {
    char unknown[0x18];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of them.
struct RecordList {
    // The vector's iterator over constant entries: a class around the element pointer.
    struct const_iterator {
        const Record *pointer;

        const_iterator(const Record *pointer) : pointer(pointer)
        {
        }
        const_iterator(const const_iterator &other) : pointer(other.pointer)
        {
        }
        const Record &operator*() const
        {
            return *pointer;
        }
        const_iterator &operator++()
        {
            ++pointer;
            return *this;
        }
        bool operator!=(const const_iterator &other) const
        {
            return pointer != other.pointer;
        }
    };

    Record *func_00164780(const_iterator first, const_iterator last, Record *destination);

    Allocator allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
Record *func_001641B0(RecordList::const_iterator first, RecordList::const_iterator last, Record *destination,
                      Allocator &, Tag);

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` with the vector's allocator
// (0x1641B0) and returns the end of the copy. Called by 0x164C20, its insert.
Record *RecordList::func_00164780(const_iterator first, const_iterator last, Record *destination)
{
    return func_001641B0(first, last, destination, allocator, Tag());
}
