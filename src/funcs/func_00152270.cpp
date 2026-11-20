// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    virtual long __stdcall func_00152270(void **object);  // slot 60

    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

struct Table_300 {
    unsigned long words[0xc0];
};

extern Table_300 *data_00264E68;

struct Guid;
extern const Guid data_001E1350;

extern "C" void *memset(void *destination, int value, unsigned int size);

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

    Object_001E1270()
    {
        memset(&saved, 0, sizeof(saved));
        memset(&current, 0, sizeof(current));
        buffer = 0;
        references = 0;
    }
    ~Object_001E1270() { data_002650D8->func_00154F80(this); }

    long func_001521E0();

    Table_300 current;
    Table_300 saved;
    void *buffer;
    unsigned long references;
};

// Creates an Object_001E1270 (both tables cleared), gets its interface data_001E1350 and sets it up
// (func_001521E0); *object is the result or null. E_NOTIMPL before the table at data_00264E68 exists,
// E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E0F00::func_00152270(void **object)
{
    if (data_00264E68) {
        Object_001E1270 *created = new Object_001E1270;
        if (created) {
            long result = created->func_00151D70(&data_001E1350, (void **)&created);
            if (result >= 0) {
                result = created->func_001521E0();
                if (result >= 0) {
                    *object = created;
                    return 0;
                }
            }
            delete created;
            *object = 0;
            return result;
        }
        *object = 0;
        return 0x8007000e;
    }
    return 0x80004001;
}
