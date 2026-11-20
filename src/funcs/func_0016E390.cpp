// The entries of the list at +0x3bc of the class whose table is at 0x1E3B90 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` entries of uninitialised storage at `first` with copies of `value`.
void func_0016E390(Item *first, unsigned int count, const Item &value, Allocator &, Tag);

// Fills `count` entries of uninitialised storage at `first` with copies of `value` (each copy only when the
// destination is not null, as placement construction does): the library's fill for this vector, called by
// 0x16E5B0.
void func_0016E390(Item *first, unsigned int count, const Item &value, Allocator &, Tag)
{
    for (; 0 < count; --count, ++first) {
        if (first)
            *first = value;
    }
}
