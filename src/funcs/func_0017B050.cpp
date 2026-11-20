// The objects in the list at +0x40 of the MThread class (table 0x1E41D8).
struct Client;

// A std::vector of them.
struct ClientList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Client **pointer;

        iterator(Client **pointer) : pointer(pointer)
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

    void func_0017B050(unsigned int count, Client *value);
    void func_0017ADB0(iterator where, unsigned int count, Client *const &value);
    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Client **first;
    Client **last;
    Client **end;
};

// Resizes the vector to `count` pointers: appends copies of `value` (through the insert 0x17ADB0) or erases the
// pointers past `count` (0x160AA0, the same function as the other vectors' erase).
void ClientList::func_0017B050(unsigned int count, Client *value)
{
    if (size() < count)
        func_0017ADB0(end_(), count - size(), value);
    else if (count < size())
        func_00160AA0(begin() + count, end_());
}
