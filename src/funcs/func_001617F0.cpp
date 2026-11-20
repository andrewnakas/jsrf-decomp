// The 0x244-byte entries of a list in MGameInput8 (the size of DirectInput's DIDEVICEINSTANCEA).
struct Info {
    char unknown[0x244];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` entries of uninitialised storage at `first` with copies of `value`.
void func_00160830(Info *first, unsigned int count, const Info &value, Allocator &, Tag);

// A std::vector of them.
struct InfoList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Info *pointer;

        iterator(Info *pointer) : pointer(pointer)
        {
        }
        iterator(const iterator &other) : pointer(other.pointer)
        {
        }
    };

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    unsigned int capacity() const
    {
        return first == 0 ? 0 : end - first;
    }
    // Fills `count` places from `where` and returns the end of the fill.
    Info *fill(Info *where, unsigned int count, const Info &value)
    {
        func_00160830(where, count, value, allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    iterator insert(iterator where, const Info &value)
    {
        return func_00161670(where, value);
    }
    void func_001617F0(const Info &value);
    iterator func_00161670(iterator where, const Info &value);

    Allocator allocator;
    Info *first;
    Info *last;
    Info *end;
};

// Appends an entry: in place while there is room, otherwise through the insert 0x161670, which grows the block.
void InfoList::func_001617F0(const Info &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        func_00161670(end_(), value);
}
