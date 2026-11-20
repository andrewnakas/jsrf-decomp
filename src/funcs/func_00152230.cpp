// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

struct Table_300 {
    unsigned long words[0xc0];
};

// A class whose table is at 0x1E1270 (8 slots; Release 0x152230, created by 0x152270).
struct Object_001E1270 {
    virtual long __stdcall func_00151D70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_00152150();  // slot 1
    virtual unsigned long __stdcall func_00152230();  // slot 2
    virtual void __stdcall func_00152210();  // slot 3
    virtual void __stdcall func_00151DB0();  // slot 4
    virtual long __stdcall func_00151DD0(float first, float second, int mask);  // slot 5
    virtual long __stdcall func_00152060(void *data, int kind);  // slot 6
    virtual void __stdcall func_00152110();  // slot 7

    ~Object_001E1270() { data_002650D8->func_00154F80(this); }

    Table_300 current;
    Table_300 saved;
    void *buffer;
    unsigned long references;
};

// Release: the last reference deletes the object, whose destructor takes it off the device's list.
unsigned long __stdcall Object_001E1270::func_00152230()
{
    if (--references == 0) {
        delete this;
        return 0;
    }
    return references;
}
