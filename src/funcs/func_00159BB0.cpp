extern "C" void *memset(void *destination, int value, unsigned int size);
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);
// Puts the object in the list at data_00265120 (E_OUTOFMEMORY when the list cannot grow).
long __stdcall func_00159E90(void *link, void *object);

// One of the 0x20-byte slots of 0x1E1640's array.
struct Slot {
    unsigned char bytes[0x20];
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0

    long __stdcall func_00159BB0(unsigned int count, unsigned long flags);

    Slot *slots;
    unsigned int count;
};

// Sets the object up for count slots (cleared, from func_00145A2F) and puts it in the list. E_INVALIDARG for no
// slots, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E1640::func_00159BB0(unsigned int count, unsigned long flags)
{
    if (count) {
        unsigned int size = count * sizeof(Slot);
        void *memory = func_00145A2F(0, size, 0x3000, 4);
        if (memory) {
            memset(memory, 0, size);
            slots = (Slot *)memory;
            this->count = count;
            func_00159E90(&slots, this);
            return 0;
        }
        return 0x8007000e;
    }
    return 0x80070057;
}
