void __cdecl operator delete(void *memory) throw();
extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

// The C runtime's throwers: std::out_of_range for a bad position (0x182AE9) and std::length_error for a string that
// would be too long (0x182B41, called with the string in ecx).
void __cdecl func_00182AE9();

// A std::string: the characters live in the 16-byte buffer while they fit (fewer than 16 reserved).
struct String {
    char *pointer()
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    const char *pointer() const
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    // Ends the string after `count` characters.
    void end(unsigned int count)
    {
        pointer()[size = count] = 0;
    }

    void func_00182B41() const;
    void func_00160710(unsigned int count, unsigned int keep);
    bool func_001608B0(unsigned int count, bool trim);
    String &func_001609E0(unsigned int position, unsigned int count);
    String &func_00160AE0(const String &other, unsigned int position, unsigned int count);
    String &func_00160B90(const char *characters, unsigned int count);

    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// Assigns `count` characters of `other` from `position` (fewer when it ends first); from itself by erasing the rest.
// Throws for a position past the end.
String &String::func_00160AE0(const String &other, unsigned int position, unsigned int count)
{
    if (other.size < position)
        func_00182AE9();
    unsigned int length = other.size - position;
    if (count < length)
        length = count;
    if (this == &other) {
        func_001609E0(position + length, 0xffffffff);
        func_001609E0(0, position);
    } else if (func_001608B0(length, true)) {
        memcpy(pointer(), other.pointer() + position, length);
        end(length);
    }
    return *this;
}
