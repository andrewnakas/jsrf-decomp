struct Object_001E1640;
// Takes the object apart: empties its slots, frees the array and takes it off the list.
void __stdcall func_00159C20(Object_001E1640 *object);

struct Slot;

// A class whose table is at 0x1E1640 (26 slots, 0x18 bytes; created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_00159D40();  // slot 2

    ~Object_001E1640() {}

    Slot *slots;
    unsigned int count;
    int value_0C;
    int value_10;
    unsigned long references;
};

// Release: the last reference takes the object apart (func_00159C20) and deletes it.
unsigned long __stdcall Object_001E1640::func_00159D40()
{
    if (--references == 0) {
        func_00159C20(this);
        delete this;
        return 0;
    }
    return references;
}
