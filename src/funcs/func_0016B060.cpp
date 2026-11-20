void __cdecl operator delete(void *memory) throw();

// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers (a voice's list at +0x10, and the elements of the list at +0x20).
struct BufferList {
    BufferList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    BufferList(const BufferList &other);
    ~BufferList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }
    BufferList &operator=(const BufferList &other);

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// A std::vector of those lists (a voice's list at +0x20).
struct GroupList {
    // The vector's iterator: a class around the element pointer.
    struct iterator {
        BufferList *pointer;

        iterator(BufferList *pointer) : pointer(pointer)
        {
        }
        iterator(const iterator &other) : pointer(other.pointer)
        {
        }
        BufferList &operator*() const
        {
            return *pointer;
        }
        iterator &operator++()
        {
            ++pointer;
            return *this;
        }
        iterator &operator--()
        {
            --pointer;
            return *this;
        }
        bool operator!=(const iterator &other) const
        {
            return pointer != other.pointer;
        }
    };

    // The vector's iterator over constant lists: a class around the element pointer.
    struct const_iterator {
        const BufferList *pointer;

        const_iterator(const BufferList *pointer) : pointer(pointer)
        {
        }
        const_iterator(const const_iterator &other) : pointer(other.pointer)
        {
        }
    };

    BufferList *func_0016B060(const_iterator first, const_iterator last, BufferList *destination);

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Copies the lists from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy.
BufferList *func_0016ADC0(GroupList::const_iterator first, GroupList::const_iterator last, BufferList *destination,
                          Allocator &, Tag);

// Copies the lists from `first` up to `last` into uninitialised storage at `destination` with the vector's allocator
// (0x16ADC0) and returns the end of the copy. Called by 0x16B2D0, the vector's insert.
BufferList *GroupList::func_0016B060(const_iterator first, const_iterator last, BufferList *destination)
{
    return func_0016ADC0(first, last, destination, allocator, Tag());
}
