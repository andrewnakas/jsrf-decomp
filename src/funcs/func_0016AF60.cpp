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

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Destroys the lists from `first` up to `last`.
void func_0016AC50(BufferList *first, BufferList *last, Allocator &allocator, Tag) throw();

// A std::vector of those lists (a voice's list at +0x20).
struct GroupList {
    void func_0016AF60(BufferList *first, BufferList *last);

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Destroys the lists from `first` up to `last` with the vector's allocator (0x16AC50).
void GroupList::func_0016AF60(BufferList *first, BufferList *last)
{
    func_0016AC50(first, last, allocator, Tag());
}
