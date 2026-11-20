// The 0x18-byte records of a list of the class whose table is at 0x1E19E0.
struct Record {
    char unknown[0x18];
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
    };

    iterator func_00164880(iterator from, iterator to);

    char allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Copies the records from `first` up to `last` to `destination` and returns the end of the copy.
inline Record *copy(RecordList::iterator first, RecordList::iterator last, Record *destination)
{
    for (; first.pointer != last.pointer; ++destination, ++first.pointer)
        *destination = *first.pointer;
    return destination;
}

// Erases the records from `from` up to `to`: moves the tail down over them. Returns `from` (0x164F20 calls it).
RecordList::iterator RecordList::func_00164880(iterator from, iterator to)
{
    if (from.pointer != to.pointer)
        last = copy(to, iterator(last), from.pointer);
    return from;
}
