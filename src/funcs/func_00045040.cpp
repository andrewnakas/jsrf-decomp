struct Vector3 {
    float x;
    float y;
    float z;
};

// An entry of 0x20 bytes of the table at +0x138.
struct Entry_00045040 {
    Vector3 position;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    float unknown_18;
    float unknown_1c;
};

// What +0x7c points at: slot 6 takes the table.
struct Buffer_00045040 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual int __stdcall slot6(Entry_00045040 *entries, int count, int size);
};

// The node class whose table is at 0x1CA788.
struct Object_00044AE0 {
    char unknown_000[0x7c];
    Buffer_00045040 *buffer;
    char unknown_080[0xb8];
    Entry_00045040 *entries;

    void func_00045040(int index, Vector3 *position, int a, float size, int b);
};

// Called by func_00045220 and func_00045B70: fills entry `index` of the table at +0x138 (the position, `size` twice,
// `b`, `a` and 0) and hands the table to slot 6 of +0x7c (1 entry of 0x20 bytes).
void Object_00044AE0::func_00045040(int index, Vector3 *position, int a, float size, int b)
{
    entries[index].position.x = position->x;
    entries[index].position.y = position->y;
    entries[index].position.z = position->z;
    entries[index].unknown_1c = size;
    entries[index].unknown_18 = size;
    entries[index].unknown_0c = b;
    entries[index].unknown_10 = a;
    entries[index].unknown_14 = 0;
    buffer->slot6(entries, 1, 0x20);
}
