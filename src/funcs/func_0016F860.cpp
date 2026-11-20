// The entries of the list at +0x3bc of the classes whose tables are at 0x1E3B90 and 0x1E3C08 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};
struct Tag {
};

// Fills `count` entries of uninitialised storage at `first` with copies of `value`.
void func_0016E390(Item *first, unsigned int count, const Item &value, Allocator &, Tag);

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
    Item *fill(Item *where, unsigned int count, const Item &value)
    {
        func_0016E390(where, count, value, allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    void func_0016F860(const Item &value);
    iterator func_0016EFB0(iterator where, const Item &value);

    Allocator allocator;
    Item *first;
    Item *last;
    Item *end;
};

// Appends an entry: in place while there is room, otherwise through the insert 0x16EFB0, which grows the block.
void ItemList::func_0016F860(const Item &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        func_0016EFB0(end_(), value);
}
