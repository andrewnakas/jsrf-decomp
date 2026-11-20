// The objects MGameInput8 keeps in its list at +0x20.
struct Registered;

// A std::vector of them.
struct RegisteredList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Registered **pointer;

        iterator(Registered **pointer) : pointer(pointer)
        {
        }
        iterator(const iterator &other) : pointer(other.pointer)
        {
        }
        iterator operator+(unsigned int count) const
        {
            return iterator(pointer + count);
        }
    };

    iterator begin()
    {
        return iterator(first);
    }
    iterator end_()
    {
        return iterator(last);
    }


    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    void func_001615F0(unsigned int count, Registered *value);
    void func_00161010(iterator where, unsigned int count, Registered *const &value);
    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// Resizes the vector to `count` pointers: appends copies of `value` (through the insert 0x161010) or erases the
// pointers past `count` (0x160AA0).
void RegisteredList::func_001615F0(unsigned int count, Registered *value)
{
    if (size() < count)
        func_00161010(end_(), count - size(), value);
    else if (count < size())
        func_00160AA0(begin() + count, end_());
}
