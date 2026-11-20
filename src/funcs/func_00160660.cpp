// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// The empty tag the library passes by value to pick a copy loop.
struct Tag {
};

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
        Info &operator*() const
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
    Info *first;
    Info *last;
    Info *end;
};

// Copies the entries from `first` up to `last` backwards so that the copy ends at `destination`; returns the start
// of the copy.
InfoList::iterator func_00160140(InfoList::iterator first, InfoList::iterator last,
                                 InfoList::iterator destination, Tag);

// The backward copy for this vector's iterators: passes them on to 0x160140 with the tag (called by 0x1612B0, the
// vector's insert).
InfoList::iterator func_00160660(InfoList::iterator first, InfoList::iterator last, InfoList::iterator destination)
{
    return func_00160140(first, last, destination, Tag());
}
