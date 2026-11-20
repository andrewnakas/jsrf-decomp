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
    virtual float __stdcall slot34(int index);
    virtual float __stdcall slot35(int index);
};

extern Interface_00265110 *data_00265110;

// A class whose table is at 0x1E144C (11 slots; Release 0x157DB0).
struct Object_001E144C {
    virtual void __stdcall func_00157BF0(int index, float value);  // slot 8

    char unknown_04[8];
    float current;
    float second;
    float value;
    float first;
};

// Reads two values for the index from slots 34 and 35 of the object at 0x265110 and keeps the value (0 for 0).
void __stdcall Object_001E144C::func_00157BF0(int index, float value)
{
    current = first = data_00265110->slot34(index);
    second = data_00265110->slot35(index);
    if (value != 0.0f)
        this->value = value;
    else
        this->value = 0;
}
