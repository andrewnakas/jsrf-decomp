void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);
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
    virtual long __stdcall func_00152060(void *data, int kind);  // slot 6

    Table_100 current[3];
    Table_100 unknown_304[3];
    Saved *saved;
};

// Slot 6: keeps a copy of table kind (1 to 3) of the current three (func_0014A83E with 0x40) and hands out the
// copy for slot 7 (0x152110) to write back. E_FAIL while a copy is out, E_INVALIDARG for no pointer or another kind,
// E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E1270::func_00152060(void *data, int kind)
{
    if (saved == 0) {
        if (data) {
            Saved *copy = (Saved *)func_0014A83E(0x40, sizeof(Saved));
            if (copy) {
                saved = copy;
                switch (kind) {
                case 1:
                    copy->target = &current[0];
                    break;
                case 2:
                    copy->target = &current[1];
                    break;
                case 3:
                    copy->target = &current[2];
                    break;
                default:
                    func_0014A85B(copy);
                    saved = 0;
                    return 0x80070057;
                }
                saved->words = *saved->target;
                *(Table_100 **)data = &saved->words;
                return 0;
            }
            return 0x8007000e;
        }
        return 0x80070057;
    }
    return 0x80004005;
}
