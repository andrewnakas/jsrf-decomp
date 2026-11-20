struct Object_000FC4D0 {
    char unknown_00[0x44];
    unsigned int flags;

    void func_000FC4D0(unsigned int mask, int set);
};

// Sets or clears the mask in the flags at 0x44.
void Object_000FC4D0::func_000FC4D0(unsigned int mask, int set)
{
    if (set) {
        flags |= mask;
    } else {
        flags &= ~mask;
    }
}
