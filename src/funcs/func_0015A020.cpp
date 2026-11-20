struct Interface_00265110;

extern Interface_00265110 *data_00265110;
extern void *data_00265114;
extern void *data_00265118;
extern void *data_0026511C;

// The factory object whose table is at 0x1E13F0 (11 slots, 8 bytes).
struct Object_001E13F0 {
    virtual long __stdcall func_0015A020(Interface_00265110 *source);  // slot 3

    unsigned long references;
};

long __stdcall func_00159F80(void *link, Interface_00265110 *object, void *value);
long __stdcall func_0015AA70(void *object);
// Six set-up steps that do nothing in this build (the linker folded them into the `xor eax, eax; ret 4` at
// 0x14D080), and the teardown steps of func_0015A110 that undo them.
long __stdcall func_0014D080_9(Object_001E13F0 *object);
long __stdcall func_0014D080_10(Object_001E13F0 *object);
long __stdcall func_0014D080_11(Object_001E13F0 *object);
long __stdcall func_0014D080_12(Object_001E13F0 *object);
long __stdcall func_0014D080_13(Object_001E13F0 *object);
long __stdcall func_0014D080_14(Object_001E13F0 *object);
void __stdcall func_00011C80_7(Object_001E13F0 *object);
void __stdcall func_00011C80_8(Object_001E13F0 *object);
void __stdcall func_00011C80_9(Object_001E13F0 *object);
void __stdcall func_00011C80_10(Object_001E13F0 *object);
void __stdcall func_00011C80_11(Object_001E13F0 *object);
void __stdcall func_00011C80_12(Object_001E13F0 *object);
void __stdcall func_0015AAB0(void *object);
// Frees the list at data_00265120.
void __stdcall func_00159E20(void *link);

// Slot 3: sets the engine up on the interface step by step; when a step fails, undoes it and the steps before it
// in reverse order (as func_0015A110 does), forgets the interface and returns the step's result.
// E_INVALIDARG without an interface.
long __stdcall Object_001E13F0::func_0015A020(Interface_00265110 *source)
{
    if (source) {
        long result = func_00159F80(&references, source, this);
        if (result >= 0) {
            result = func_0014D080_9(this);
            if (result >= 0) {
                result = func_0015AA70(this);
                if (result >= 0) {
                    result = func_0014D080_10(this);
                    if (result >= 0) {
                        result = func_0014D080_11(this);
                        if (result >= 0) {
                            result = func_0014D080_12(this);
                            if (result >= 0) {
                                result = func_0014D080_13(this);
                                if (result >= 0) {
                                    result = func_0014D080_14(this);
                                    if (result >= 0)
                                        return 0;
                                    func_00011C80_7(this);
                                }
                                func_00011C80_8(this);
                            }
                            func_00011C80_9(this);
                        }
                        func_00011C80_10(this);
                    }
                    func_00011C80_11(this);
                }
                func_0015AAB0(this);
            }
            func_00011C80_12(this);
        }
        func_00159E20(&references);
        data_00265110 = 0;
        data_00265114 = 0;
        data_00265118 = 0;
        data_0026511C = 0;
        return result;
    }
    return 0x80070057;
}
