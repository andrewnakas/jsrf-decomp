struct Guid;

// Eleven words copied out together.
struct Block {
    unsigned long words[11];
};

// The class whose table is at 0x1E1968.
struct Object_001E1968 {
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual long __stdcall func_00162960(int *value, Block *block);

    char unknown_04[0x48];
    int value;
    char unknown_50[0x21c];
    Block block;
};

// Slot 23: copies the word at +0x4c and the eleven words at +0x26c out, each to its pointer when that is not null.
long __stdcall Object_001E1968::func_00162960(int *value, Block *block)
{
    if (value)
        *value = this->value;
    if (block)
        *block = this->block;
    return 0;
}
