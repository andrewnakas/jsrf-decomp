/* sym: ??0Object_001E3DE4@@QAE@PAUUnknown@@@Z = 0x00174310 */
struct Guid;
struct Unknown;
struct Object_001E3D30;

// The class whose table is at 0x1E3DE4 (0x38 bytes): the reader the opening makes.
struct Object_001E3DE4 {
    Object_001E3DE4(Unknown *outer);
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_001746E0(void *argument1, void *argument2);

    char unknown_04[0x34];
};

// The class whose table is at 0x1E3D30.
struct Object_001E3D30 {
    virtual long __stdcall slot0(const Guid &id, void **object);

    Unknown *outer;
    long references;
    void *file;
    Object_001E3DE4 *reader;
};

// The second step of opening: makes a 0x1E3DE4 object, opens it on this object (its slot 3) and keeps it at +0x10 with
// a reference added; the creation's own reference is let go either way. E_OUTOFMEMORY when the allocation fails; if
// the constructor throws, its exception handler frees the memory.
long __stdcall func_00173040(Object_001E3D30 *self)
{
    Object_001E3DE4 *reader = new Object_001E3DE4(0);
    if (!reader)
        return 0x8007000E;
    long result = reader->func_001746E0(self, 0);
    if (result >= 0) {
        reader->slot1();
        self->reader = reader;
    }
    reader->slot2();
    return result;
}
