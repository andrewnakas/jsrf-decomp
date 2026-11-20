// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0
};

// QueryInterface of the base: E_NOINTERFACE.
long __stdcall Object_001E10E8::func_0014D490(const void *iid, void **object)
{
    return 0x80004002;
}
