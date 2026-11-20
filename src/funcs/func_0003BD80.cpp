struct Entry_0003BD80 {
    char unknown_00[0xc];
    int first;
    int second;
    int unknown_14;
    int state;
    char unknown_1c[0x40];
};

// The table of object 0x19B5: its entries (0x5c bytes) and a cursor.
struct Table_0003BEC0 {
    char unknown_00[0x44];
    int cursor;
    int count;
    int unknown_4c;
    Entry_0003BD80 *entries;

    int func_0003BD80(int first, int second, int index);
};

// Fills the entry at the cursor with two values and state 2 and moves the cursor on, when the cursor is at `index`.
int Table_0003BEC0::func_0003BD80(int first, int second, int index)
{
    if (cursor == index) {
        entries[cursor].first = first;
        entries[cursor].second = second;
        entries[cursor].state = 2;
        cursor++;
        return 1;
    }
    return 0;
}
