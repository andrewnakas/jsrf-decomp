// The objects MGameInput8 keeps in its list at +0x20.
struct Registered;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// Fills `count` pointers of uninitialised storage at `first` with `value`: the library's helper for vectors of
// pointers, the one every vector here calls.
void func_0017ABC0(void **first, unsigned int count, void *const &value, Allocator &, Tag);

// A std::vector of pointers.
struct RegisteredList {
    Registered **func_00179D80(Registered **where, unsigned int count, Registered *const &value);

    Allocator allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// Fills `count` places of uninitialised storage from `where` with `value` and returns the end of the fill. The linker
// folded the same member of all six vectors of pointers here into this one (their inserts 0x161010, 0x163430,
// 0x1690C0, 0x16A790, 0x17A000 and 0x17ADB0 call it).
Registered **RegisteredList::func_00179D80(Registered **where, unsigned int count, Registered *const &value)
{
    func_0017ABC0((void **)where, count, reinterpret_cast<void *const &>(value), allocator, Tag());
    return where + count;
}
