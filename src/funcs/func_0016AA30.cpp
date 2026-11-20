/* sym: ??0BufferList@@QAE@ABU0@@Z = 0x0016AA30 */
// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Copies the pointers from `first` up to `last` into uninitialised storage at `destination` and returns the end of the
// copy: the library's uninitialised copy for vectors of pointers.
void **func_0017AB40(void **first, void **last, void **destination, Allocator &, Tag);

// A std::vector of pointers (a voice's list at +0x10, and the elements of the list at +0x20).
struct BufferList {
    BufferList(const BufferList &other);

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
    // Frees the block and leaves the vector empty (the library's copy of the vectors' destructor, which every vector of
    // pointers here shares).
    void func_0017ABF0();

    // Copies into uninitialised storage with the vector's allocator.
    Buffer **ucopy(Buffer **from, Buffer **to, Buffer **destination)
    {
        return (Buffer **)func_0017AB40((void **)from, (void **)to, (void **)destination, allocator, Tag());
    }

    Buffer *const *begin() const
    {
        return first;
    }
    Buffer *const *end_() const
    {
        return last;
    }

    bool func_0016A730(unsigned int capacity);

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Copy constructor: takes a block for the other list's pointers (0x16A730) and copies them; frees the block again if
// the copy throws.
BufferList::BufferList(const BufferList &other)
{
    if (func_0016A730(other.size())) {
        try {
            last = ucopy((Buffer **)other.begin(), (Buffer **)other.end_(), first);
        } catch (...) {
            func_0017ABF0();
            throw;
        }
    }
}
