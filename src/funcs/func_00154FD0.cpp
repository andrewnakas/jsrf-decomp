int func_0018CDF0();

// Direct3D's state: data_002650DC is set while the device is running, data_002650D4 while it holds the push
// buffer (released one reference at a time by func_0018CDF0), data_002650E0 while it is shared.
extern unsigned long data_002650DC;
extern unsigned long data_002650D4;
extern unsigned long data_002650E0;

// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    long func_00154FD0();
    void func_001521B0();
    void func_0014D9C0();
    void func_0014FD70();
    void func_00011C90_1();
    void func_001564A0();
    void func_00154E70();
    void func_00150F70();
    void func_00154B20();
};

// Shuts the device down: releases its parts in order, then lets go of Direct3D.
long Object_001E0F00::func_00154FD0()
{
    func_001521B0();
    func_0014D9C0();
    func_0014FD70();
    func_00011C90_1();
    func_001564A0();
    func_00154E70();
    func_00150F70();
    func_00154B20();
    if (data_002650DC) {
        if (data_002650D4) {
            while (func_0018CDF0())
                ;
            data_002650D4 = 0;
        }
        if (!data_002650E0)
            data_002650DC = 0;
    }
    return 0;
}
