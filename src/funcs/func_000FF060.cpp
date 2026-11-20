// Object 0x1163 (func_00079B50 and func_0007A8B0 look it up and call this).
struct Object_000FEDB0 {
    char unknown_000[0x144];
    unsigned int flags;

    void func_000FF060(int set);
};

// Sets or clears the top flag bit at 0x144.
void Object_000FEDB0::func_000FF060(int set)
{
    if (set) {
        flags |= 0x80000000;
    } else {
        flags &= 0x7fffffff;
    }
}
