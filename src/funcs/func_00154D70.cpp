struct Source {
    int unknown_00;
    void *data;
};

long __stdcall func_0014CB20(Source *source);
long __stdcall func_001BB780(Source *source);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7
    void func_00153A90();

    char unknown_04[0x60];
    void *data;
};

long __stdcall Object_001E0F00::func_00154D70(int kind, Source *source)
{
    switch (kind) {
    case 1:
        return func_0014CB20(source);
    case 2: {
        long result = func_001BB780(source);
        if (result >= 0) {
            data = source->data;
            func_00153A90();
        }
        return result;
    }
    }
    return 0x80070057;
}
