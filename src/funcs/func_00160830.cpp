// The 0x244-byte entries of a list in MGameInput8.
struct Info {
    char unknown[0x244];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` entries of uninitialised storage at `first` with copies of `value`.
void func_00160830(Info *first, unsigned int count, const Info &value, Allocator &, Tag);

// Fills `count` entries of uninitialised storage at `first` with copies of `value` (each copy only when the
// destination is not null, as placement construction does): the library's fill for this vector, called by
// 0x1609B0, 0x1612B0 and 0x1617F0.
void func_00160830(Info *first, unsigned int count, const Info &value, Allocator &, Tag)
{
    for (; 0 < count; --count, ++first) {
        if (first)
            *first = value;
    }
}
