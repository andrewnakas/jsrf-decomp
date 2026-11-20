long __stdcall func_0018CC50(unsigned long first, unsigned long second, void *memory, void **object);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    void *func_00154900(unsigned int size, int flags);
    long func_00154EE0(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void *object;
    unsigned long value_08;
    unsigned long value_0C;
    long value_10;
};

// Kind 1 of 0x152BC0 (0x18 bytes).
struct Object_001E1298 : Object_001E1290 {
    long func_001526E0(unsigned long argument1, unsigned long argument2, unsigned long argument3);
};

// Sets kind 1 up: keeps the three arguments, gets memory for the third from the device (func_00154900), creates
// the object (func_0018CC50) and, when that works, keeps it and puts this on the device's list (func_00154EE0).
long Object_001E1298::func_001526E0(unsigned long argument1, unsigned long argument2, unsigned long argument3)
{
    value_08 = argument1;
    value_0C = argument2;
    value_10 = argument3;
    void *memory = data_002650D8->func_00154900(argument3, 0);
    void *created = 0;
    long result = func_0018CC50(argument1, argument2, memory, &created);
    if (result >= 0) {
        object = created;
        data_002650D8->func_00154EE0(this);
    }
    return result;
}
