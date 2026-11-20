extern unsigned long data_00264C18;
extern unsigned long data_00264C1C;
void __stdcall func_00190490(unsigned long value);

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00155B40();  // slot 9

    void *object;
    void *resource;
    unsigned long shader;
    unsigned long extra;
    unsigned int vertexCount;
};

// Makes the object's shader (+0xC) current unless it already is; 1 while the global at 0x264C18 is set.
long __stdcall Object_001E10E8::func_00155B40()
{
    if (data_00264C18 == 0) {
        if (data_00264C1C != shader) {
            func_00190490(shader);
            data_00264C1C = shader;
        }
        return 0;
    }
    return 1;
}
