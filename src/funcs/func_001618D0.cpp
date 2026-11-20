extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

// The 0x244-byte entries of a list in MGameInput8 (the size of DirectInput's DIDEVICEINSTANCEA).
struct Info {
    char unknown[0x244];
};

// A std::vector of them.
struct InfoList {
    void func_001617F0(const Info &value);

    char allocator;
    Info *first;
    Info *last;
    Info *end;
};

// The callback 0x161920 passes on with a list: appends a copy of the entry it is given (or an empty one) to the list
// (through the append 0x1617F0) and asks for the next one.
int __stdcall func_001618D0(const Info *instance, void *list)
{
    if (list) {
        Info copy;
        if (instance)
            copy = *instance;
        else
            memset(&copy, 0, sizeof(copy));
        ((InfoList *)list)->func_001617F0(copy);
    }
    return 1;
}
