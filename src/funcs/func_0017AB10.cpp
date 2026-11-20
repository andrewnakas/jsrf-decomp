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

    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// Copies the pointers from `first` up to `last` backwards so that the copy ends at `destination`.
inline RegisteredList::iterator copy_backward(RegisteredList::iterator first, RegisteredList::iterator last,
                                              RegisteredList::iterator destination)
{
    while (first.pointer != last.pointer)
        *--destination.pointer = *--last.pointer;
    return destination;
}

// Copies the pointers from `first` up to `last` backwards so that the copy ends at `destination`, and returns the
// start of the copy: the library's copy_backward. The linker folded the same function for all six vectors of
// pointers here into this one (their inserts 0x161010, 0x163430, 0x1690C0, 0x16A790, 0x17A000 and 0x17ADB0 call it).
RegisteredList::iterator func_0017AB10(RegisteredList::iterator first, RegisteredList::iterator last,
                                       RegisteredList::iterator destination)
{
    return copy_backward(first, last, destination);
}
