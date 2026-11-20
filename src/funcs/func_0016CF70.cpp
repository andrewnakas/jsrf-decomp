// The entries of the list at +0x3bc of the class whose table is at 0x1E3B90 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// The empty tag the library passes by value to pick a copy loop.
struct Tag {
};

// A std::vector of them.
struct ItemList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Item *pointer;

        iterator(Item *pointer) : pointer(pointer)
        {
        }
        iterator(const iterator &other) : pointer(other.pointer)
        {
        }
        Item &operator*() const
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
    Item *first;
    Item *last;
    Item *end;
};

// Copies the entries from `first` up to `last` backwards so that the copy ends at `destination`; returns the start
// of the copy.
ItemList::iterator func_0016C650(ItemList::iterator first, ItemList::iterator last,
                                 ItemList::iterator destination, Tag);

// The backward copy for this vector's iterators: passes them on to 0x16C650 with the tag (called by 0x16EB90, the
// vector's insert).
ItemList::iterator func_0016CF70(ItemList::iterator first, ItemList::iterator last, ItemList::iterator destination)
{
    return func_0016C650(first, last, destination, Tag());
}
