struct Interface_00265110;

extern Interface_00265110 *data_00265110;
extern void *data_00265114;
extern void *data_00265118;
extern void *data_0026511C;

// The factory object whose table is at 0x1E13F0 (11 slots, 8 bytes).
struct Object_001E13F0 {
    virtual long __stdcall func_00156D60(const void *iid, void **object);  // slot 0

    unsigned long references;
};

// Six teardown steps that do nothing in this build (the linker folded them into the `ret 4` at 0x11C80).
void __stdcall func_00011C80_7(Object_001E13F0 *object);
void __stdcall func_00011C80_8(Object_001E13F0 *object);
void __stdcall func_00011C80_9(Object_001E13F0 *object);
void __stdcall func_00011C80_10(Object_001E13F0 *object);
void __stdcall func_00011C80_11(Object_001E13F0 *object);
void __stdcall func_00011C80_12(Object_001E13F0 *object);
void __stdcall func_0015AAB0(void *object);
// Frees the list at data_00265120.
void __stdcall func_00159E20(void *link);

// Takes the factory object apart (its Release, 0x156DC0, calls it) and forgets the objects at data_00265110 to
// data_0026511C.
void __stdcall func_0015A110(Object_001E13F0 *object)
{
    func_00011C80_7(object);
    func_00011C80_8(object);
    func_00011C80_9(object);
    func_00011C80_10(object);
    func_00011C80_11(object);
    func_0015AAB0(object);
    func_00011C80_12(object);
    func_00159E20(&object->references);
    data_00265110 = 0;
    data_00265114 = 0;
    data_00265118 = 0;
    data_0026511C = 0;
}
