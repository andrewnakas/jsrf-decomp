// The objects MGameInput8 keeps in its list at +0x20.
struct Registered;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

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

    Registered **func_0016A570(iterator first, iterator last, Registered **destination);

    Allocator allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// The library's uninitialised copy for vectors of pointers (one function for all six vectors here).
Registered **func_0017AB40(RegisteredList::iterator first, RegisteredList::iterator last, Registered **destination,
                           Allocator &, Tag);

// Copies the pointers from `first` up to `last` into uninitialised storage at `destination` with the vector's
// allocator and returns the end of the copy. The linker folded the same member of all six vectors of pointers here
// into this one (their inserts 0x161010, 0x163430, 0x1690C0, 0x16A790, 0x17A000 and 0x17ADB0 call it).
Registered **RegisteredList::func_0016A570(iterator first, iterator last, Registered **destination)
{
    return func_0017AB40(first, last, destination, allocator, Tag());
}
