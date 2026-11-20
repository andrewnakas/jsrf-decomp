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

// A std::vector of those lists (a voice's list at +0x20).
struct GroupList {
    void func_0016B6A0(unsigned int size);
    void func_0016B5E0(unsigned int size, BufferList value);

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Resizes the vector to `size` lists, new ones empty (0x16B5E0 with an empty list).
void GroupList::func_0016B6A0(unsigned int size)
{
    func_0016B5E0(size, BufferList());
}
