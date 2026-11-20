/* sym: ??4BufferList@@QAEAAU0@ABU0@@Z = 0x0016AAD0 */
void __cdecl operator delete(void *memory) throw();

// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// A std::vector of pointers.
struct BufferList;

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
    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Assigns `value` to every list from `first` up to `last` (the list's assignment, 0x16AAD0).
void func_0016AD50(BufferList *first, BufferList *last, const BufferList &value)
{
    for (; first != last; ++first)
        *first = value;
}
