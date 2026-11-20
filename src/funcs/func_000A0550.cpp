// The player object: func_00098DF0 and func_0009A170, which func_00099A50 and func_0009B240 call with
// their own `this`, call this with theirs.
struct Object_000A1C50 {
    char unknown_000[0xac8];
    unsigned int cursor;

    int func_000A0550();
};

extern int data_00215170[];

// Returns the next of the four entries of data_00215170, by the cursor at 0xac8, which wraps after the
// fourth.
int Object_000A1C50::func_000A0550()
{
    int value = data_00215170[cursor];
    if (++cursor >= 4) {
        cursor = 0;
    }
    return value;
}
