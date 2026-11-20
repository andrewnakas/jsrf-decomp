unsigned long __stdcall func_00192950(void *object);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014D4A0();  // slot 1
    virtual unsigned long __stdcall func_0014D080();  // slot 2
    virtual long __stdcall func_00155E50(int kind);  // slot 3

    void *first;
    void *second;
    long value_0C;
    long value_10;
    long value_14;
    long value_18;
};

// Kinds 1 and 2: the values at +0xC and +0x10. 3 and 4: the values at +0x14 and +0x18 if the object at +4 or +8
// exists. 5 and 6: the object at +4 or +8, after func_00192950 took a reference to it. Otherwise 0.
long __stdcall Object_001E10E8::func_00155E50(int kind)
{
    switch (kind) {
    case 1:
        return value_0C;
    case 2:
        return value_10;
    case 3:
        if (first)
            return value_14;
        break;
    case 4:
        if (second)
            return value_18;
        break;
    case 5:
        if (first) {
            func_00192950(first);
            return (long)first;
        }
        break;
    case 6:
        if (second) {
            func_00192950(second);
            return (long)second;
        }
        break;
    }
    return 0;
}
