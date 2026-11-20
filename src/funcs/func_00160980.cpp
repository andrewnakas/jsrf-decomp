// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of them.
struct InfoList {
    // The vector's iterator over constant entries: a class around the element pointer.
    struct const_iterator {
        const Info *pointer;

        const_iterator(const Info *pointer) : pointer(pointer)
        {
        }
        const_iterator(const const_iterator &other) : pointer(other.pointer)
        {
        }
        const Info &operator*() const
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

    Info *func_00160980(const_iterator first, const_iterator last, Info *destination);

    Allocator allocator;
    Info *first;
    Info *last;
    Info *end;
};

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
Info *func_001606A0(InfoList::const_iterator first, InfoList::const_iterator last, Info *destination, Allocator &, Tag);

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` with the vector's allocator
// (0x1606A0) and returns the end of the copy. Called by 0x1612B0.
Info *InfoList::func_00160980(const_iterator first, const_iterator last, Info *destination)
{
    return func_001606A0(first, last, destination, allocator, Tag());
}
