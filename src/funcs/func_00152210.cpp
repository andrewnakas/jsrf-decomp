struct Table_300 {
    unsigned long words[0xc0];
};

void __stdcall func_0018CB60(int kind, Table_300 *table);

// A class whose table is at 0x1E1270 (8 slots).
struct Object_001E1270 {
    virtual void __stdcall func_00152210();  // slot 3

    Table_300 current;
};

void __stdcall Object_001E1270::func_00152210()
{
    func_0018CB60(1, &current);
}
