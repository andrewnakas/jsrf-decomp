// One of the objects in MGameSound8's list at +0x1c (the voices, class 0x1E3B00).
struct Voice;

// MGameSound8's list of them: a std::vector of pointers.
struct VoiceList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Voice **pointer;

        iterator(Voice **pointer) : pointer(pointer)
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

    void func_00169360(unsigned int count, Voice *value);
    void func_001690C0(iterator where, unsigned int count, Voice *const &value);
    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Voice **first;
    Voice **last;
    Voice **end;
};

// Resizes the vector to `count` pointers: appends copies of `value` (through the insert 0x1690C0) or erases the
// pointers past `count` (0x160AA0, the same function as the other vectors' erase).
void VoiceList::func_00169360(unsigned int count, Voice *value)
{
    if (size() < count)
        func_001690C0(end_(), count - size(), value);
    else if (count < size())
        func_00160AA0(begin() + count, end_());
}
