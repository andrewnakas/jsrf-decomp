// The objects MGameInput8 keeps in its list at +0x20.
struct Registered;

// A std::vector of pointers.
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
    };

    iterator func_00160AA0(iterator from, iterator to);

    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// Copies the pointers from `first` up to `last` to `destination` and returns the end of the copy.
inline Registered **copy(RegisteredList::iterator first, RegisteredList::iterator last, Registered **destination)
{
    for (; first.pointer != last.pointer; ++destination, ++first.pointer)
        *destination = *first.pointer;
    return destination;
}

// Erases the pointers from `from` up to `to`: moves the tail down over them. Returns `from` (the resize 0x1615F0
// calls it).
RegisteredList::iterator RegisteredList::func_00160AA0(iterator from, iterator to)
{
    if (from.pointer != to.pointer)
        last = copy(to, iterator(last), from.pointer);
    return from;
}
