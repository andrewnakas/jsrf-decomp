// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value` (each store only when the destination is
// not null, as placement construction does): the library's fill for vectors of pointers, the one every vector here
// calls (their appends 0x161780, 0x1637B0, 0x16AEF0, 0x17A330 and 0x17B1E0, for instance).
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag)
{
    for (; 0 < count; --count, ++first) {
        if (first)
            *first = value;
    }
}
