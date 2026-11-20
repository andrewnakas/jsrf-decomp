struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
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
    virtual void __stdcall slot15(unsigned long value);
};

extern Interface_00265110 *data_00265110;

// A class whose table is at 0x1E141C (12 slots; Release 0x1579A0).
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4

    unsigned long value_04;
    char unknown_08[0x100C];
    Interface *object;
    char unknown_1018[4];
    unsigned long value_101C;
};

long __stdcall func_00159F30(void *unused, void *object);

// Takes the object apart: its slot 4, releases the object at +0x1014 until its Release returns 0, hands the value
// at +0x101C to slot 15 of the object at 0x265110 and takes the object off the list at 0x265120.
void __stdcall func_001570B0(Object_001E141C *object)
{
    object->func_00157960();
    if (object->object) {
        while (object->object->slot2())
            ;
        object->object = 0;
    }
    data_00265110->slot15(object->value_101C);
    func_00159F30(&object->value_04, object);
}
