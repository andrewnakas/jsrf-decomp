struct Guid;

struct First;
struct Second;

// The class whose table is at 0x1E4020: one of the classes the MFile2 factory (0x1E3F1C) creates (func_00176460
// builds it).
struct Object_001E4020 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual long __stdcall slot15(int);
    virtual void slot16();
    virtual long __stdcall func_00178B30(int flush);
    long __stdcall func_00178830();
    void func_00178000();

    char unknown_04[8];
    First *first;
    Second *second;
};

// Slot 17: with a non-zero argument runs 0x178830; otherwise calls slot 15 with 0 and, when that works, 0x178000.
long __stdcall Object_001E4020::func_00178B30(int flush)
{
    long result;
    if (flush) {
        result = func_00178830();
    } else {
        result = slot15(0);
        if (result >= 0)
            func_00178000();
    }
    return result;
}
