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
        iterator operator+(unsigned int count) const
        {
            return iterator(pointer + count);
        }
    };

    iterator begin()
    {
        return iterator(first);
    }
    iterator end_()
    {
        return iterator(last);
    }

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    void func_00164F20(unsigned int count, Record value);
    void func_00164C20(iterator where, unsigned int count, const Record &value);
    iterator func_00164880(iterator from, iterator to);

    char allocator;
    Record *first;
    Record *last;
    Record *end;
};

// Resizes the vector to `count` records: appends copies of `value` (through the insert 0x164C20) or erases the
// records past `count` (0x164880).
void RecordList::func_00164F20(unsigned int count, Record value)
{
    if (size() < count)
        func_00164C20(end_(), count - size(), value);
    else if (count < size())
        func_00164880(begin() + count, end_());
}
