struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17(unsigned int handle);
};

extern Device_00251D6C *data_00251D6C;

// Use counts of the device's 0x1000 handles.
extern int data_002537D0[];

// Drops one use of a handle (below 0x1000); after the last, frees it (device slot 17). Its caller (0x4756E) pushes
// the handle and loads no object, and it pops its argument: it is __stdcall.
void __stdcall func_0006EAE0(unsigned int handle)
{
    if (handle < 0x1000 && data_002537D0[handle] > 0u) {
        if (--data_002537D0[handle] <= 0) {
            data_00251D6C->slot17(handle);
            data_002537D0[handle] = 0;
        }
    }
}
