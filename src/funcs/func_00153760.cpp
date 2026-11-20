void __stdcall func_00199BE0(void *object);

// A class whose table is at 0x1E1328 (6 slots).
struct Object_001E1328 {
    virtual long __stdcall func_00153760();  // slot 3

    void *object;
};

long __stdcall Object_001E1328::func_00153760()
{
    func_00199BE0(object);
    return 0;
}
