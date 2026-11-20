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

// Fills `count` lists of uninitialised storage at `first` with copies of `value`.
void func_0016AF80(BufferList *first, unsigned int count, const BufferList &value, Allocator &allocator, Tag);

// A std::vector of those lists (a voice's list at +0x20).
struct GroupList {
    BufferList *func_0016B0D0(BufferList *where, unsigned int count, const BufferList &value);

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// Fills `count` places from `where` with copies of `value` (0x16AF80) and returns the end of the fill.
BufferList *GroupList::func_0016B0D0(BufferList *where, unsigned int count, const BufferList &value)
{
    func_0016AF80(where, count, value, allocator, Tag());
    return where + count;
}
