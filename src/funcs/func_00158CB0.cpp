// An entry of the buffer: three zeros and -1 when it is set up.
struct Entry {
    unsigned long first;
    unsigned long second;
    unsigned long third;
    long fourth;
};

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
    virtual long __stdcall slot54(int kind, unsigned long count, unsigned long third, unsigned long flags,
                                  Buffer **buffer);
};

extern Interface_00265110 *data_00265110;

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded

    long __stdcall func_00158CB0(unsigned long first, unsigned long second);

    Buffer *buffer;
    unsigned long count;
};

// Sets the object up for first entries: a buffer from slot 54 of the interface at data_00265110 (0x42, flag 0x100
// of second) with every entry set to (0, 0, 0, -1) when it can be locked. E_INVALIDARG for no entries.
long __stdcall Object_001E1598::func_00158CB0(unsigned long first, unsigned long second)
{
    if (first) {
        Buffer *created = 0;
        long result = data_00265110->slot54(0x42, first, 0, second & 0x100, &created);
        if (result < 0)
            return result;
        Entry *data = 0;
        if (created->slot4((void **)&data, 0) >= 0) {
            for (unsigned int i = 0; i < first; i++) {
                data->first = 0;
                data->second = 0;
                data->third = 0;
                data->fourth = -1;
                data++;
            }
            created->slot5();
        }
        count = first;
        buffer = created;
        return 0;
    }
    return 0x80070057;
}
