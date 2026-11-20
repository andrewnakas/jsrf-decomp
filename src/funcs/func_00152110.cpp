int __stdcall func_0014A85B(void *handle);

struct Table_100 {
    unsigned long words[0x40];
};

// The 0x100 bytes kept for a table and where they go back to.
struct Saved {
    Table_100 *target;
    Table_100 words;
};

// A class whose table is at 0x1E1270 (8 slots; Release 0x152230, created by 0x152270).
struct Object_001E1270 {
    virtual void __stdcall func_00152110();  // slot 7

    char unknown_04[0x600];
    Saved *saved;
};

// Slot 7: copies the saved words back to where they came from and frees them.
void __stdcall Object_001E1270::func_00152110()
{
    if (saved) {
        *saved->target = saved->words;
        func_0014A85B(saved);
        saved = 0;
    }
}
