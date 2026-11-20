extern "C" unsigned int strlen(const char *);
extern "C" void *memcpy(void *, const void *, unsigned int);

// Object 0x12b0: a copy of its text at +0xa0 and three values.
struct Object_0006EC00 {
    char unknown_00[0x98];
    int flags;
    int value;
    char *text;
    char unknown_a4[0x14];
    int first;

    void func_0006F100(const char *text, int first, int flags, int value);
};

// Replaces the object's copy of its text and its three values.
void Object_0006EC00::func_0006F100(const char *source, int first, int flags, int value)
{
    if (text) {
        operator delete(text);
    }
    text = 0;
    unsigned int size = strlen(source) + 1;
    text = (char *)operator new(size);
    memcpy(text, source, size);
    this->first = first;
    this->flags = flags;
    this->value = value;
}
