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

    Item *func_0016E580(const_iterator first, const_iterator last, Item *destination);

    Allocator allocator;
    Item *first;
    Item *last;
    Item *end;
};

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
Item *func_0016CFB0(ItemList::const_iterator first, ItemList::const_iterator last, Item *destination, Allocator &, Tag);

// Copies the entries from `first` up to `last` into uninitialised storage at `destination` with the vector's allocator
// (0x16CFB0) and returns the end of the copy. Called by 0x16EB90.
Item *ItemList::func_0016E580(const_iterator first, const_iterator last, Item *destination)
{
    return func_0016CFB0(first, last, destination, allocator, Tag());
}
