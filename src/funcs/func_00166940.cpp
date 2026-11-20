struct Guid;
struct Object_001E21A0;

// What slot 3 takes: the object it belongs to and a 1-based index.
struct Key {
    Object_001E21A0 *owner;
    unsigned short index;
};

// The objects in the table at +0x18.
struct Entry {
    virtual void slot0();
    virtual unsigned long __stdcall slot1();
};

// The class whose table is at 0x1E21A0.
struct Object_001E21A0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00166940(const Key *key, Entry **entry, void *);

    char unknown_04[8];
    void *ready;
    char unknown_10[8];
    Entry *entries[1];
};

// Slot 3: gives out entry `index` (1-based) of the table at +0x18, with a reference, for a key that names this object.
// E_INVALIDARG for a null pointer, a key of another object, index 0 or an empty entry, 0x800401F0 (not initialised)
// while +0xc is null.
long __stdcall Object_001E21A0::func_00166940(const Key *key, Entry **entry, void *)
{
    if (ready) {
        if (entry && key->owner == this && key->index) {
            unsigned int index = key->index - 1;
            if (entries[index]) {
                entries[index]->slot1();
                *entry = entries[index];
                return 0;
            }
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
