// The allocator of a vector, and the empty tag the library passes by value to pick this copy loop.
struct Allocator {
};

struct Tag {
};

// Copies the pointers from `first` up to `last` into uninitialised storage at `destination` (each store only when the
// destination is not null, as placement construction does) and returns the end of the copy: the library's
// uninitialised copy for vectors of pointers, the one copy every vector here calls.
void **func_0017AB40(void **first, void **last, void **destination, Allocator &, Tag)
{
    for (; first != last; ++destination, ++first) {
        if (destination)
            *destination = *first;
    }
    return destination;
}
