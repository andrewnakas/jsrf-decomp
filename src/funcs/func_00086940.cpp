struct Object_00086960 {
    virtual ~Object_00086960();
    virtual void slot1();
    virtual void slot2();
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
    virtual void func_00086940();

    char unknown_04[0x40];
    float offset[3];

    void func_00086850();
};

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();

// Slot 16 of the table at 0x1CD170: runs func_00086850 between func_001BA9C0 and func_001BAA50, after
// func_001BAAA0 on the vector at +0x44 (the same bracket the tree walkers use).
void Object_00086960::func_00086940()
{
    func_001BA9C0();
    func_001BAAA0(offset);
    func_00086850();
    func_001BAA50();
}
