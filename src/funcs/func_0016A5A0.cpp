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

    Buffer **func_0016A5A0(Buffer **first, Buffer **last, Buffer **destination);

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Copies the pointers from `first` up to `last` into uninitialised storage at `destination` and returns the end of
// the copy.
void **func_0017AB40(void **first, void **last, void **destination, Allocator &, Tag);

// A std::vector of those lists (a voice's list at +0x20).
struct GroupList {
    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Copies the pointers from `first` up to `last` into uninitialised storage at `destination` with the vector's
// allocator (0x17AB40) and returns the end of the copy.
Buffer **BufferList::func_0016A5A0(Buffer **first, Buffer **last, Buffer **destination)
{
    return (Buffer **)func_0017AB40((void **)first, (void **)last, (void **)destination, allocator, Tag());
}
