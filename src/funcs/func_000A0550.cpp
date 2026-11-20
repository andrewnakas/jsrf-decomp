struct Object_000A04F0 {
    char unknown_000[0xac8];
    unsigned int cursor;

    int func_000A0550();
};

extern int data_00215170[];

// Returns the next of the four entries of data_00215170, by the cursor at 0xac8, which wraps after the
// fourth.
int Object_000A04F0::func_000A0550()
{
    int value = data_00215170[cursor];
    if (++cursor >= 4) {
        cursor = 0;
    }
    return value;
}
