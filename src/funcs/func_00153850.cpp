void __stdcall func_00199BC0(void *object);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// A class whose table is at 0x1E1328 (6 slots; Release 0x153850, created by 0x1539B0).
struct Object_001E1328 {
    virtual long __stdcall func_001537C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001537B0();  // slot 1
    virtual unsigned long __stdcall func_00153850();  // slot 2
    virtual long __stdcall func_00153760();  // slot 3
    virtual void __stdcall func_00153780();  // slot 4
    virtual long __stdcall func_00153790(unsigned long first, unsigned long second, unsigned long third);  // slot 5

    ~Object_001E1328() {}

    void *object;
    unsigned long references;
};

// Release: the last reference releases the object at +4, takes this one off the device's list and deletes it.
unsigned long __stdcall Object_001E1328::func_00153850()
{
    if (--references == 0) {
        func_00199BC0(object);
        data_002650D8->func_00154F80(this);
        delete this;
        return 0;
    }
    return references;
}
