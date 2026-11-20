struct Object_0007FA70 {
    char unknown_000[0x88];
    int first;
    int firsts[0x11];
    int second;
    int seconds[0x11];

    void func_0007FA70();
};

// Fills the 17-word tables at +0x8c and +0xd4 with the words at +0x88 and +0xd0.
void Object_0007FA70::func_0007FA70()
{
    for (int i = 0; i < 0x11; i++) {
        firsts[i] = first;
        seconds[i] = second;
    }
}
