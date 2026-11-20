// The objects MGameInput8 keeps in its list at +0x20.
struct Registered;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value`: the library's helper for vectors of
// pointers, the one every vector here calls.
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag);

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

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    unsigned int capacity() const
    {
        return first == 0 ? 0 : end - first;
    }
    // Fills `count` places from `where` and returns the end of the fill.
    Registered **fill(Registered **where, unsigned int count, Registered *const &value)
    {
        func_0017ABC0((void **)where, count, reinterpret_cast<void *const &>(value), allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    void insert(iterator where, Registered *const &value)
    {
        func_00161010(where, 1, value);
    }
    void func_00161780(Registered *const &value);
    void func_00161010(iterator where, unsigned int count, Registered *const &value);

    Allocator allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// Appends a pointer: in place while there is room, otherwise through the insert 0x161010, which grows the block.
void RegisteredList::func_00161780(Registered *const &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        insert(end_(), value);
}
