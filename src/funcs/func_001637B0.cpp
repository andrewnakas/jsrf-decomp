// The entries in the lists at +0x3c8 and +0x3d8 of the class whose table is at 0x1E1968.
struct Entry;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value`: the library's helper for vectors of
// pointers, the one every vector here calls.
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag);

// A std::vector of pointers.
struct EntryList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        Entry **pointer;

        iterator(Entry **pointer) : pointer(pointer)
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
    Entry **fill(Entry **where, unsigned int count, Entry *const &value)
    {
        func_0017ABC0((void **)where, count, reinterpret_cast<void *const &>(value), allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    void insert(iterator where, Entry *const &value)
    {
        func_00163430(where, 1, value);
    }
    void func_001637B0(Entry *const &value);
    void func_00163430(iterator where, unsigned int count, Entry *const &value);

    Allocator allocator;
    Entry **first;
    Entry **last;
    Entry **end;
};

// Appends a pointer: in place while there is room, otherwise through the insert 0x163430, which grows the block.
void EntryList::func_001637B0(Entry *const &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        insert(end_(), value);
}
