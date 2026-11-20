struct Entry;

extern Entry *data_00264E70;
extern unsigned int data_00264E74;
extern Entry **data_00264E6C;

int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// The class whose table is at 0x1E12F8 (12 slots, 8 bytes; Release 0x153670, created by 0x1536E0).
struct Object_001E12F8 {
    virtual long __stdcall func_00153300(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0();  // slot 1: AddRef
    virtual unsigned long __stdcall func_00153670();  // slot 2: Release
    virtual long __stdcall func_001533D0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 3
    virtual long __stdcall func_00152E30(int index);  // slot 4
    virtual long __stdcall func_00153520(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 5
    virtual long __stdcall func_00152E90(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 6
    virtual long __stdcall func_001530F0(unsigned long argument1, unsigned long argument2);  // slot 7
    virtual long __stdcall func_00152FE0(unsigned long argument1);  // slot 8
    virtual long __stdcall func_001531E0();  // slot 9
    virtual long __stdcall func_00153240(unsigned long value);  // slot 10
    virtual long __stdcall func_001532A0();  // slot 11

    ~Object_001E12F8() {}

    unsigned long references;
};

// Release: the last reference frees the table at data_00264E70 (func_00145A5D with 0x8000), forgets it and the
// list at data_00264E6C, takes the object off the device's list and deletes it.
unsigned long __stdcall Object_001E12F8::func_00153670()
{
    if (--references == 0) {
        if (data_00264E70) {
            func_00145A5D(data_00264E70, 0, 0x8000);
            data_00264E70 = 0;
            data_00264E74 = 0;
            data_00264E6C = 0;
            data_002650D8->func_00154F80(this);
        }
        delete this;
        return 0;
    }
    return references;
}
