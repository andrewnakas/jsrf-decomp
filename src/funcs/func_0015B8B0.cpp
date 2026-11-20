/* sym: ?func_00158A50@Object_001E1538@@UAGJK@Z = 0x0015B8B0 */
// The four quad writers (0x30 bytes each, SSE): destination, source, index, table, scale.
void func_0015B7C0(void *destination, unsigned long source, long index, unsigned long *table, float scale);
void func_0015B770(void *destination, unsigned long source, long index, unsigned long *table, float scale);
void func_0015B860(void *destination, unsigned long source, long index, unsigned long *table, float scale);
void func_0015B810(void *destination, unsigned long source, long index, unsigned long *table, float scale);

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5

    unsigned long words[0x42];
    float value_10C;
    unsigned long value_110;
    unsigned long *target;
    unsigned long *source;
    char *cursor;
    long count;
    unsigned long value_124;
};

// The class whose table is at 0x1E1538 (kind 1 of 0x158A80).
struct Object_001E1538 : Object_001E14D8 {
    virtual long __stdcall func_00158A50(unsigned long value);  // slot 5, at 0x15B8B0

    unsigned long value_128;
};

// Slot 5: writes the next 0x30-byte quad at the cursor with one of the four writers (chosen by +0x110 and the
// mode at +0x128), then advances the cursor and counts it.
long __stdcall Object_001E1538::func_00158A50(unsigned long value)
{
    if (value_110 == 0) {
        if (value_128 == 1)
            func_0015B7C0(cursor, value, count, target, value_10C);
        else
            func_0015B770(cursor, value, count, target, value_10C);
    } else {
        if (value_128 == 1)
            func_0015B860(cursor, value, count, target, value_10C);
        else
            func_0015B810(cursor, value, count, target, value_10C);
    }
    count++;
    cursor += 0x30;
    return 0;
}
