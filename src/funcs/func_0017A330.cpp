// The objects in the list at +0x10 of the MEvent class (table 0x1E4130).
struct Listener;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value`: the library's helper for vectors of
// pointers, the one every vector here calls.
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag);

// A std::vector of pointers.
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
    Listener **fill(Listener **where, unsigned int count, Listener *const &value)
    {
        func_0017ABC0((void **)where, count, reinterpret_cast<void *const &>(value), allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    void insert(iterator where, Listener *const &value)
    {
        func_0017A000(where, 1, value);
    }
    void func_0017A330(Listener *const &value);
    void func_0017A000(iterator where, unsigned int count, Listener *const &value);

    Allocator allocator;
    Listener **first;
    Listener **last;
    Listener **end;
};

// Appends a pointer: in place while there is room, otherwise through the insert 0x17A000, which grows the block.
void ListenerList::func_0017A330(Listener *const &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        insert(end_(), value);
}
