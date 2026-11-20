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

    Allocator allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
Record *func_001641B0(RecordList::const_iterator first, RecordList::const_iterator last, Record *destination,
                      Allocator &, Tag);

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` (each copy only when the
// destination is not null, as placement construction does) and returns the end of the copy: the library's
// uninitialised copy for this vector, which its member 0x164780 calls.
Record *func_001641B0(RecordList::const_iterator first, RecordList::const_iterator last, Record *destination,
                      Allocator &, Tag)
{
    for (; first != last; ++destination, ++first) {
        if (destination)
            *destination = *first;
    }
    return destination;
}
