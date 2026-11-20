// Fills the 0x60-byte record at the cursor from the values (0x15C280, register arguments).
void __fastcall func_0015C280(char *record, const float *values, unsigned long extra);

// The class whose table is at 0x1E1610 (11 slots, 0x20 bytes; created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_0015C5D0(unsigned long value);  // slot 5

    void *voice;
    unsigned long value_08;
    unsigned long value_0C;
    unsigned long value_10;
    char *cursor;
    int position;
};

// Slot 5: counts one more record and fills it at the cursor (func_0015C280), then moves the cursor on.
long __stdcall Object_001E1610::func_0015C5D0(unsigned long value)
{
    position++;
    func_0015C280(cursor, (const float *)value, value_0C);
    cursor += 0x60;
    return 0;
}
