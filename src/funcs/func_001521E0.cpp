struct Table_300 {
    unsigned long words[0xc0];
};

void __stdcall func_0018CBC0(Table_300 *table);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154EE0(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E1270 (8 slots; Release 0x152230, created by 0x152270).
struct Object_001E1270 {
    virtual long __stdcall func_00151D70(const void *iid, void **object);  // slot 0
    long func_001521E0();

    Table_300 current;
    Table_300 saved;
};

// Fills both tables (func_0018CBC0) and puts the object on the device's list.
long Object_001E1270::func_001521E0()
{
    func_0018CBC0(&saved);
    func_0018CBC0(&current);
    data_002650D8->func_00154EE0(this);
    return 0;
}
