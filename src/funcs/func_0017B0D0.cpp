// The objects in the list at +0x10 of the MEvent class (table 0x1E4130).
struct Listener;

// A std::vector of them.
struct ListenerList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Listener **pointer;

        iterator(Listener **pointer) : pointer(pointer)
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

    void func_0017B0D0(unsigned int count, Listener *value);
    void func_0017A000(iterator where, unsigned int count, Listener *const &value);
    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;
};

// Resizes the vector to `count` pointers: appends copies of `value` (through the insert 0x17A000) or erases the
// pointers past `count` (0x160AA0, the same function as the other vectors' erase).
void ListenerList::func_0017B0D0(unsigned int count, Listener *value)
{
    if (size() < count)
        func_0017A000(end_(), count - size(), value);
    else if (count < size())
        func_00160AA0(begin() + count, end_());
}
