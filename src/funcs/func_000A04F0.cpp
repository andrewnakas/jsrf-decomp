// The player object: func_000996A0 calls this with its own `this`, as it calls func_0007F9B0.
struct Object_000A1C50 {
    char unknown_000[0xac8];
    unsigned int cursor;

    int func_000A04F0();
};

extern int data_00215140[];

// Returns the next of the four entries of data_00215140, by the cursor at 0xac8, which wraps after the
// fourth.
int Object_000A1C50::func_000A04F0()
{
    int value = data_00215140[cursor];
    if (++cursor >= 4) {
        cursor = 0;
    }
    return value;
}
