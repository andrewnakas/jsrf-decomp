// The value at +0x38 of what +0x20 points at.
struct Scale_000477C0 {
    char unknown_00[0x38];
    float value;
};

struct Owner_000477C0 {
    char unknown_00[0x20];
    Scale_000477C0 *scale;
};

struct Device_00251D6C {
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
    virtual int __stdcall slot26(int kind, float *matrix, int unknown);
};

extern Device_00251D6C *data_00251D6C;

struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[0x34];
    float unknown_38;

    void func_000477C0(Owner_000477C0 *owner);
};

// Reads a matrix from slot 26 of the device (1) and sets +0x38 to its element 11 times the owner's scale times
// 0.0022, plus 0.02, at most 0.3.
void Object_00047470::func_000477C0(Owner_000477C0 *owner)
{
    float matrix[16];
    data_00251D6C->slot26(1, matrix, 0);
    unknown_38 = matrix[11] * owner->scale->value * 0.0022f + 0.02f;
    if (unknown_38 > 0.3f)
        unknown_38 = 0.3f;
}
