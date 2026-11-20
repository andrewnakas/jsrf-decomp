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
    };

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    iterator func_0016EFB0(iterator where, const Item &value);
    void func_0016EB90(iterator where, unsigned int count, const Item &value);

    char allocator;
    Item *first;
    Item *last;
    Item *end;
};

// Inserts one copy of `value` before `where` (through 0x16EB90) and returns the position of the new entry, which the
// insert may have moved to a new block.
ItemList::iterator ItemList::func_0016EFB0(iterator where, const Item &value)
{
    unsigned int offset = size() == 0 ? 0 : where.pointer - first;
    func_0016EB90(where, 1, value);
    return iterator(first + offset);
}
