// The entries of the list at +0x3bc of the class whose table is at 0x1E3B90 (0x254 bytes each).
struct Item {
    char unknown[0x254];
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
        iterator &operator++()
        {
            ++pointer;
            return *this;
        }
        bool operator!=(const iterator &other) const
        {
            return pointer != other.pointer;
        }
    };
};

// The library's copy loop for this vector's iterators (inline: the out-of-line copy below passes its iterators on).
inline Item *copyLoop(ItemList::iterator first, ItemList::iterator last, Item *destination)
{
    for (; first.pointer != last.pointer; ++destination, ++first.pointer)
        *destination = *first.pointer;
    return destination;
}

// Copies the entries from `first` up to `last` to `destination` and returns the end of the copy (the vector's resize
// 0x16EEF0 calls it to erase its tail).
Item *func_0016CF30(ItemList::iterator first, ItemList::iterator last, Item *destination)
{
    return copyLoop(first, last, destination);
}
