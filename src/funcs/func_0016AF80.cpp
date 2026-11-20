/* sym: ??0BufferList@@QAE@ABU0@@Z = 0x0016AA30 */
/* sym: ??3@YAXPAX0@Z = 0x00011C90 */
inline void *__cdecl operator new(unsigned int, void *where)
{
    return where;
}
// Placement delete: an empty function, out of line (the linker folded it with the other empty functions at 0x11C90).
void __cdecl operator delete(void *, void *);
void __cdecl operator delete(void *memory) throw();

// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct BufferList;

struct Allocator {
    void func_0016A700(BufferList *pointer);
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
        const BufferList &operator*() const
        {
            return *pointer;
        }
        const_iterator &operator++()
        {
            ++pointer;
            return *this;
        }
        bool operator!=(const const_iterator &other) const
        {
            return pointer != other.pointer;
        }
    };

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Constructs a copy of `value` in the storage at `pointer`.
inline void construct(BufferList *pointer, const BufferList &value)
{
    new ((void *)pointer) BufferList(value);
}

// Fills `count` places of uninitialised storage from `first` with copies of `value` (copy constructor 0x16AA30). If a
// copy throws, destroys the copies made so far (0x16A700) and throws on. The vector's member 0x16B0D0 and its insert
// 0x16B2D0 call it.
void func_0016AF80(BufferList *first, unsigned int count, const BufferList &value, Allocator &allocator, Tag)
{
    BufferList *next = first;
    try {
        for (; 0 < count; --count, ++first)
            construct(first, value);
    } catch (...) {
        for (; next != first; ++next)
            allocator.func_0016A700(next);
        throw;
    }
}
