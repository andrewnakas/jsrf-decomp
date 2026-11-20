struct Object_000FF060 {
    char unknown_000[0x144];
    unsigned int flags;

    void func_000FF060(int set);
};

// Sets or clears the top flag bit at 0x144.
void Object_000FF060::func_000FF060(int set)
{
    if (set) {
        flags |= 0x80000000;
    } else {
        flags &= 0x7fffffff;
    }
}
