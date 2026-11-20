void __cdecl operator delete(void *memory) throw();

// The objects in the voice's lists.
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers.
struct BufferList {
    BufferList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
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

// Destroys the lists from `first` up to `last`, each freeing its block: the library's destroy-range helper for the
// voice's vector of lists (0x1E3B00 +0x20), which its destructor 0x16B180 and the list's destructor 0x16B090 call.
void func_0016AC50(BufferList *first, BufferList *last, Allocator &, Tag) throw()
{
    for (; first != last; ++first)
        first->~BufferList();
}
