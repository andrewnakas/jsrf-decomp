// The entries of the list at +0x3bc of the class whose table is at 0x1E3B90 (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// Assigns `value` to every entry from `first` up to `last` (called by 0x16EB90).
void func_0016C620(Item *first, Item *last, const Item &value)
{
    for (; first != last; ++first)
        *first = value;
}
