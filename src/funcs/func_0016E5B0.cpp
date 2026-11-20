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

// A std::vector of them.
struct ItemList {
    Item *func_0016E5B0(Item *where, unsigned int count, const Item &value);

    Allocator allocator;
    Item *first;
    Item *last;
    Item *end;
};

// Fills `count` places from `where` with copies of `value` with the vector's allocator (0x16E390) and returns the end
// of the fill. Called by 0x16EB90, the vector's insert.
Item *ItemList::func_0016E5B0(Item *where, unsigned int count, const Item &value)
{
    func_0016E390(where, count, value, allocator, Tag());
    return where + count;
}
