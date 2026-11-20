extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

// VirtualAlloc (address, size, allocation type, protection) and VirtualProtect (address, size, protection, old
// protection).
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);
long __stdcall func_00145A99(void *first, unsigned long second, unsigned long third, unsigned long *result);
// Puts the object in the list at data_00265120.
long __stdcall func_00159E90(void *link, void *object);

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual long __stdcall slot5();
};

struct Interface_00265110 {
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
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual long __stdcall slot54(int kind, unsigned long size, unsigned long third, unsigned long flags,
                                  Buffer **buffer);
};

extern Interface_00265110 *data_00265110;

// The class whose table is at 0x1E1610 (11 slots, 0x20 bytes; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_00159180(const void *iid, void **object);  // slot 0

    long __stdcall func_001591C0(unsigned long first, unsigned long second, unsigned long third);

    Buffer *buffer;
    unsigned long count;
    void *entries;
    unsigned long capacity;
};

// Sets the object up: second 0x60-byte entries of cleared, committed memory (read-only once set up), a buffer of
// first words from slot 54 of the interface at data_00265110 (0x142, flag 0x100 of third; cleared, 0x60 bytes per
// word, when it can be locked); puts the object in the list. E_OUTOFMEMORY, or the interface's failure.
long __stdcall Object_001E1610::func_001591C0(unsigned long first, unsigned long second, unsigned long third)
{
    unsigned long size = second * 0x60;
    void *memory = func_00145A2F(0, size, 0x3000, 4);
    if (memory) {
        memset(memory, 0, size);
        unsigned long bytes = first * 4;
        Buffer *created = 0;
        long result = data_00265110->slot54(0x142, bytes, 0, third & 0x100, &created);
        if (result < 0)
            return result;
        void *data = 0;
        if (created->slot4(&data, 0) >= 0) {
            memset(data, 0, bytes * 24);
            created->slot5();
        }
        buffer = created;
        count = first;
        entries = memory;
        capacity = second;
        first = 0;
        func_00145A99(memory, size, 2, &first);
        func_00159E90(&buffer, this);
        return 0;
    }
    return 0x8007000e;
}
