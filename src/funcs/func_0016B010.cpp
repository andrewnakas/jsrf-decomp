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

    iterator func_0016B010(iterator from, iterator to);

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// The library's helpers for this vector: the copy loop (0x16AC10) and the destruction of a range (0x16AC50).
BufferList *func_0016AC10(GroupList::iterator first, GroupList::iterator last, BufferList *destination, Tag);
void func_0016AC50(BufferList *first, BufferList *last, Allocator &, Tag);

// Assigns the lists from `first` up to `last` to the lists from `destination` on.
inline BufferList *copy(GroupList::iterator first, GroupList::iterator last, BufferList *destination)
{
    return func_0016AC10(first, last, destination, Tag());
}

// Destroys the lists from `first` up to `last`.
inline void destroy(BufferList *first, BufferList *last, Allocator &allocator)
{
    func_0016AC50(first, last, allocator, Tag());
}

// Erases the lists from `from` up to `to`: assigns the tail down over them and destroys the lists left past the new
// end. Returns `from` (the resize 0x16B5E0 calls it).
GroupList::iterator GroupList::func_0016B010(iterator from, iterator to)
{
    if (from != to) {
        BufferList *end = copy(to, iterator(last), from.pointer);
        destroy(end, last, allocator);
        last = end;
    }
    return from;
}
