void __cdecl operator delete(void *memory) throw();

// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// A std::vector of pointers.
struct BufferList;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
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

// The list allocator's destroy: runs the list's destructor, which frees its block.
void Allocator::func_0016A700(BufferList *pointer)
{
    pointer->~BufferList();
}
