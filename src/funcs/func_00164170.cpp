// The 0x18-byte records of a list of the class whose table is at 0x1E19E0.
struct Record {
    char unknown[0x18];
};

// The empty tag the library passes by value to pick a copy loop.
struct Tag {
};

// A std::vector of them.
struct RecordList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Record *pointer;

        iterator(Record *pointer) : pointer(pointer)
        {
        }
        iterator(const iterator &other) : pointer(other.pointer)
        {
        }
        Record &operator*() const
        {
            return *pointer;
        }
        iterator &operator--()
        {
            --pointer;
            return *this;
        }
        bool operator!=(const iterator &other) const
        {
            return pointer != other.pointer;
        }
    };

    char allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Copies the entries from `first` up to `last` backwards so that the copy ends at `destination`; returns the start
// of the copy.
RecordList::iterator func_00163E70(RecordList::iterator first, RecordList::iterator last,
                                  RecordList::iterator destination, Tag);

// The backward copy for this vector's iterators: passes them on to 0x163E70 with the tag (called by 0x164C20, the
// vector's insert).
RecordList::iterator func_00164170(RecordList::iterator first, RecordList::iterator last,
                                   RecordList::iterator destination)
{
    return func_00163E70(first, last, destination, Tag());
}
