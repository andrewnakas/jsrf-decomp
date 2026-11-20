// A resource the player holds at 0x70, 0x78 and 0x80; slot 2 releases it and returns the references left.
struct Resource_000A87A0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Object_000A1C50 {
    char unknown_000[0x70];
    Resource_000A87A0 *first;
    char unknown_074[4];
    Resource_000A87A0 *second;
    char unknown_07c[4];
    Resource_000A87A0 *third;

    void func_000A87A0();
};

// Called by the player's destructor (func_0007E830): releases the resources at 0x70, 0x78 and 0x80 until none of
// their references are left.
void Object_000A1C50::func_000A87A0()
{
    while (first->slot2()) {
    }
    while (second->slot2()) {
    }
    while (third->slot2()) {
    }
}
