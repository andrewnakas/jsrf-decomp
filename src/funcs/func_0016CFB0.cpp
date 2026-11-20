// The entries of the list at +0x3bc of the class whose table is at 0x1E3B90 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of them.
struct ItemList {
    // The vector's iterator over constant entries: a class around the element pointer.
    struct const_iterator {
        const Item *pointer;

        const_iterator(const Item *pointer) : pointer(pointer)
        {
        }
        const_iterator(const const_iterator &other) : pointer(other.pointer)
        {
        }
        const Item &operator*() const
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
    Item *first;
    Item *last;
    Item *end;
};

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
Item *func_0016CFB0(ItemList::const_iterator first, ItemList::const_iterator last, Item *destination, Allocator &, Tag);

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` (each copy only when the
// destination is not null, as placement construction does) and returns the end of the copy: the library's
// uninitialised copy for this vector, which its member 0x16E580 calls.
Item *func_0016CFB0(ItemList::const_iterator first, ItemList::const_iterator last, Item *destination, Allocator &, Tag)
{
    for (; first != last; ++destination, ++first) {
        if (destination)
            *destination = *first;
    }
    return destination;
}
