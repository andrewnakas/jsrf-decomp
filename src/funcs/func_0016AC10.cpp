/* sym: ??4BufferList@@QAEAAU0@ABU0@@Z = 0x0016AAD0 */
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


    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Assigns the lists from `first` up to `last` to the lists from `destination` on and returns the end of the copy: the
// library's copy loop for this vector (its erase 0x16B010 calls it).
BufferList *func_0016AC10(GroupList::iterator first, GroupList::iterator last, BufferList *destination, Tag)
{
    for (; first != last; ++destination, ++first)
        *destination = *first;
    return destination;
}
