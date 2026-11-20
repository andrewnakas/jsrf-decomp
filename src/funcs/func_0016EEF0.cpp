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
    void erase(Item *from, Item *to);

    void func_0016EEF0(unsigned int count, Item value);
    void func_0016EB90(iterator where, unsigned int count, const Item &value);

    char allocator;
    Item *first;
    Item *last;
    Item *end;
};

// Copies the entries from `first` up to `last` to `destination` and returns the end of the copy.
Item *func_0016CF30(ItemList::iterator first, ItemList::iterator last, Item *destination);

// Erases the entries from `from` up to `to`.
inline void ItemList::erase(Item *from, Item *to)
{
    if (from != to)
        last = func_0016CF30(iterator(to), iterator(last), from);
}

// Resizes the vector to `count` entries: appends copies of `value` (through the insert 0x16EB90) or erases the entries
// past `count`.
void ItemList::func_0016EEF0(unsigned int count, Item value)
{
    if (size() < count)
        func_0016EB90(iterator(last), count - size(), value);
    else if (count < size())
        erase(first + count, last);
}
