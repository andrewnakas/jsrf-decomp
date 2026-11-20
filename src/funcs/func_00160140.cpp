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

// Copies the entries from `first` up to `last` backwards so that the copy ends at `destination` and returns the start
// of the copy: the library's backward copy loop for this vector (0x160660 picks it).
InfoList::iterator func_00160140(InfoList::iterator first, InfoList::iterator last,
                                 InfoList::iterator destination, Tag)
{
    while (first != last)
        *--destination = *--last;
    return destination;
}
