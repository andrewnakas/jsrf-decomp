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

// A std::vector of them.
struct InfoList {
    Info *func_001609B0(Info *where, unsigned int count, const Info &value);

    Allocator allocator;
    Info *first;
    Info *last;
    Info *end;
};

// Fills `count` places from `where` with copies of `value` with the vector's allocator (0x160830) and returns the end
// of the fill. Called by 0x1612B0, the vector's insert.
Info *InfoList::func_001609B0(Info *where, unsigned int count, const Info &value)
{
    func_00160830(where, count, value, allocator, Tag());
    return where + count;
}
