/* sym: ??1Object_001E1290@@QAE@XZ = 0x00152690 */
unsigned long __stdcall func_00192990(void *object);

// The Direct3D device wrapper (table 0x1E0F00); data_002650D8 points at the one in use.
struct Object_001E0F00 {
    long func_00154F80(void *resource);
};

extern Object_001E0F00 *data_002650D8;

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_1();  // slot 1: AddRef, folded

    ~Object_001E1290();

    void *object;
    char unknown_08[0xC];
    unsigned long references;
};

// The class whose table is at 0x1E1298 (created by 0x152BC0).
struct Object_001E1298 : Object_001E1290 {
    virtual unsigned long __stdcall func_00152AE0();  // slot 2
};

// Release: the last reference releases the object at +4 until func_00192990 returns 0, takes this one off the
// device's list and deletes it.
unsigned long __stdcall Object_001E1298::func_00152AE0()
{
    if (--references == 0) {
        if (object) {
            while (func_00192990(object))
                ;
            object = 0;
        }
        data_002650D8->func_00154F80(this);
        delete static_cast<Object_001E1290 *>(this);
        return 0;
    }
    return references;
}
