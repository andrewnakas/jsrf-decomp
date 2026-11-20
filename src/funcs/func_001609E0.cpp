void __cdecl operator delete(void *memory) throw();
void *__cdecl func_0017CEC0(void *destination, const void *source, unsigned int size);

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
    // The grow of 0x1608B0, inlined.
    bool grow(unsigned int count, bool trim)
    {
        if (0xfffffffe < count)
            func_00182B41();
        if (reserved < count) {
            func_00160710(count, trim ? 0 : size);
        } else if (trim && count < 16) {
            if (reserved >= 16)
                operator delete(text.pointer);
            reserved = 15;
            end(0);
        } else if (count == 0) {
            end(0);
        }
        return 0 < count;
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

// Erases `count` characters from `position` (fewer when the string ends first), moving the rest down with the C
// runtime's memmove (0x17CEC0). Throws for a position past the end.
String &String::func_001609E0(unsigned int position, unsigned int count)
{
    if (size < position)
        func_00182AE9();
    if (size - position < count)
        count = size - position;
    if (0 < count) {
        func_0017CEC0(pointer() + position, pointer() + position + count, size - position - count);
        unsigned int left = size - count;
        if (grow(left, false))
            end(left);
    }
    return *this;
}
