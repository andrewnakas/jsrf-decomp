/* sym: ??0String@@QAE@PBD@Z = 0x00160EC0 */
extern "C" unsigned int __cdecl strlen(const char *text);

// A std::string: the characters live in the 16-byte buffer while they fit (fewer than 16 reserved).
struct String {
    String(const char *text);

    char *pointer()
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    void tidy()
    {
        reserved = 15;
        pointer()[size = 0] = 0;
    }
    String &func_00160B90(const char *text, unsigned int size);

    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// Makes a string of the characters at `text`. The library's code inlines this constructor; the C runtime's throwers
// at 0x182AE9 and 0x182B41 (which build a std::logic_error from a message) call this copy of it.
String::String(const char *text)
{
    tidy();
    func_00160B90(text, strlen(text));
}
