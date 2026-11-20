// The objects in the list at +0x10 of the voices (the class whose table is at 0x1E3B00).
struct Buffer;

// A std::vector of them.
struct BufferList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Buffer **pointer;

        iterator(Buffer **pointer) : pointer(pointer)
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

    void func_0016ACD0(unsigned int count, Buffer *value);
    void func_0016A790(iterator where, unsigned int count, Buffer *const &value);
    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Resizes the vector to `count` pointers: appends copies of `value` (through the insert 0x16A790) or erases the
// pointers past `count` (0x160AA0, the same function as the other vectors' erase).
void BufferList::func_0016ACD0(unsigned int count, Buffer *value)
{
    if (size() < count)
        func_0016A790(end_(), count - size(), value);
    else if (count < size())
        func_00160AA0(begin() + count, end_());
}
