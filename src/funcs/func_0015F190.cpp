/* sym: ??0Object_001E1798@@QAE@XZ = 0x0015F190 */
// What the classes whose tables are at 0x1E1798 and 0x1E17BC have in common: the keys and the references. The
// constructors 0x15F190 and 0x15F1C0 clear them before they store the table pointer.
struct KeyState {
    KeyState() : keys(0), value_48(0), references(0) {}

    char unknown_04[0x40];
    void *keys;
    void *value_48;
    unsigned long references;
};

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 : KeyState {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0015F1B0();  // slot 1
    virtual unsigned long __stdcall func_0015F2A0();  // slot 2: Release
    virtual long __stdcall func_0015F390(void *data, unsigned long size, unsigned long count);  // slot 3
    virtual unsigned int __stdcall func_0015F480();  // slot 4
    virtual void __stdcall func_0015F4A0(int index);  // slot 5
    virtual void __stdcall func_0015F450(unsigned int data, unsigned int stride, int count);  // slot 6
    virtual void __stdcall func_0015F4C0(void *out, float time);  // slot 7
    virtual long __stdcall func_0015F4E0(unsigned long first, unsigned long second);  // slot 8

    Object_001E1798();
};

// The constructor.
Object_001E1798::Object_001E1798()
{
}
