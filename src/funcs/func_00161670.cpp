// MGameInput8's 0x244-byte entries.
struct Info {
    char unknown[0x244];
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
    };

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    iterator func_00161670(iterator where, const Info &value);
    void func_001612B0(iterator where, unsigned int count, const Info &value);

    char allocator;
    Info *first;
    Info *last;
    Info *end;
};

// Inserts one copy of `value` before `where` (through 0x1612B0) and returns the position of the new entry, which the
// insert may have moved to a new block.
InfoList::iterator InfoList::func_00161670(iterator where, const Info &value)
{
    unsigned int offset = size() == 0 ? 0 : where.pointer - first;
    func_001612B0(where, 1, value);
    return iterator(first + offset);
}
