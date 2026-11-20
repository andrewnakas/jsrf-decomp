/* const: 0x80000 */
/* const: 0x200000 */
// The surface at +0xB60: a COM-style interface; slot 4 locks it (bits out), slot 5 unlocks it.
struct Surface_00120EA0 {
    virtual long __stdcall slot0();
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4(void **bits, int first, int second);
    virtual long __stdcall slot5();
};

struct Object_00120EA0 {
    char unknown_000[0xb60];
    Surface_00120EA0 *surface;

    void func_00120EF0(int value);
};

// Locks the surface, copies the second half of the locked buffer back into the first (0x80000 words), unlocks it.
void Object_00120EA0::func_00120EF0(int)
{
    void *bits;
    surface->slot4(&bits, 0, 0);
    volatile unsigned int *words = (volatile unsigned int *)bits;
    for (unsigned int i = 0; i < 0x80000; i++) {
        words[i] = words[i + 0x80000];
    }
    surface->slot5();
}
