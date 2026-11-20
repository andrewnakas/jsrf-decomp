// A row of the settings block at +0x33c (0x10 bytes): its entry count and cursor.
struct Row_000687D0 {
    int unknown_00;
    int count;
    int cursor;
    int unknown_0c;
};

// The settings block at +0x33c (0x30 bytes): one row per step.
struct Settings_000676A0 {
    Row_000687D0 rows[3];
};

// An item of the table at +0x340 (0x20 bytes): shown, and the items to its left, right, up and down.
struct Item_000687D0 {
    char unknown_00[8];
    int shown;
    char unknown_0c[4];
    int left;
    int right;
    int up;
    int down;
};

// The class whose table is at 0x1CB0F8 (constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0xa8];
    int step;
    char unknown_0ac[0x290];
    Settings_000676A0 *settings;
    Item_000687D0 *items;

    void func_000687D0();
};

// Steps the cursor of the current row back. Row 2: one back, wrapping round to the last entry. Row 0: to the first
// shown item along the left links; when that comes round to the cursor again, to the first shown item along the right
// links from the left of the item above (of item 2 for item 0), giving up where the walk started; -1 keeps it.
void Object_00067980::func_000687D0()
{
    switch (step) {
    case 2:
        settings->rows[step].cursor--;
        if (settings->rows[step].cursor < 0) {
            settings->rows[step].cursor = settings->rows[step].count - 1;
        }
        break;
    case 0: {
        Item_000687D0 *table = items;
        int cursor = settings->rows[step].cursor;
        int first = table[cursor].left;
        Item_000687D0 *item = &table[cursor];
        int index = table[cursor].left;
        while (!table[index].shown) {
            index = table[index].left;
        }
        if (index == cursor) {
            int other = table[index ? item->up : 2].left;
            while (!table[other].shown) {
                other = table[other].right;
                if (index) {
                    if (other == first) {
                        goto done;
                    }
                } else if (other == table[2].left) {
                    goto done;
                }
            }
            if (other != -1) {
                settings->rows[step].cursor = other;
                break;
            }
        }
    done:
        settings->rows[step].cursor = index;
        break;
    }
    }
}
