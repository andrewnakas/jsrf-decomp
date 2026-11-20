struct Object_000A04F0 {
    char unknown_000[0xac8];
    unsigned int cursor;

    int func_000A0520();
};

extern int data_00215160[];

// Returns the next of the four entries of data_00215160, by the cursor at 0xac8, which wraps after the
// fourth.
int Object_000A04F0::func_000A0520()
{
    int value = data_00215160[cursor];
    if (++cursor >= 4) {
        cursor = 0;
    }
    return value;
}
