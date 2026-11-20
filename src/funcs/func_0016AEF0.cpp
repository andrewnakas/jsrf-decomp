// The objects in the list at +0x10 of the voices (the class whose table is at 0x1E3B00).
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value`: the library's helper for vectors of
// pointers, the one every vector here calls.
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag);

// A std::vector of pointers.
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
    Buffer **fill(Buffer **where, unsigned int count, Buffer *const &value)
    {
        func_0017ABC0((void **)where, count, reinterpret_cast<void *const &>(value), allocator, Tag());
        return where + count;
    }
    iterator end_()
    {
        return iterator(last);
    }
    void insert(iterator where, Buffer *const &value)
    {
        func_0016A790(where, 1, value);
    }
    void func_0016AEF0(Buffer *const &value);
    void func_0016A790(iterator where, unsigned int count, Buffer *const &value);

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Appends a pointer: in place while there is room, otherwise through the insert 0x16A790, which grows the block.
void BufferList::func_0016AEF0(Buffer *const &value)
{
    if (size() < capacity())
        last = fill(last, 1, value);
    else
        insert(end_(), value);
}
