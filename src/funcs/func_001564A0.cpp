// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    void func_001564A0();
    // A step that does nothing in this build (the linker folded it into the bare `ret` at 0x11C90).
    void func_00011C90_2();
};

// One of the device's shutdown steps (func_00154FD0): passes on to an empty one.
void Object_001E0F00::func_001564A0()
{
    func_00011C90_2();
}
