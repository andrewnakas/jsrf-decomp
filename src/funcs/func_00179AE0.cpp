extern "C" int __cdecl memcmp(const void *left, const void *right, unsigned int size);

// The C runtime's thrower of std::out_of_range for a bad position.
void __cdecl func_00182AE9();

// A std::string: the characters live in the 16-byte buffer while they fit (fewer than 16 reserved).
struct String {
    const char *pointer() const
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    int func_00179AE0(unsigned int position, unsigned int count, const char *other, unsigned int otherCount) const;

    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// Compares `count` characters from `position` (fewer when the string ends first) with the `otherCount` characters at
// `other`: below 0, 0 or above 0. Throws for a position past the end.
int String::func_00179AE0(unsigned int position, unsigned int count, const char *other, unsigned int otherCount) const
{
    if (size < position)
        func_00182AE9();
    if (size - position < count)
        count = size - position;
    int result = count == 0 ? 0 : memcmp(pointer() + position, other, count < otherCount ? count : otherCount);
    return result != 0 ? result : count < otherCount ? -1 : count != otherCount;
}
