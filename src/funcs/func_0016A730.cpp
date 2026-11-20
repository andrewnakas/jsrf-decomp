void *__cdecl operator new(unsigned int size);

// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// A std::vector of pointers (a voice's list at +0x10, and the elements of the list at +0x20).
struct BufferList {
    unsigned int max_size() const
    {
        return 0xFFFFFFFF / sizeof(Buffer *);
    }

    bool func_0016A730(unsigned int capacity);
    void func_0016A680() const;

    char allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Leaves the vector empty, then takes a block for `capacity` pointers: false for none, std::length_error (0x16A680)
// past the largest size. The copy constructor 0x16AA30 and the assignment 0x16AAD0 call it.
bool BufferList::func_0016A730(unsigned int capacity)
{
    first = 0;
    last = 0;
    end = 0;
    if (capacity == 0)
        return false;
    if (max_size() < capacity)
        func_0016A680();
    else {
        first = (Buffer **)operator new(capacity * sizeof(Buffer *));
        last = first;
        end = first + capacity;
    }
    return true;
}
