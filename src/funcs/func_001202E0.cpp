struct Vector3 {
    float x;
    float y;
    float z;
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
    virtual void __stdcall slot20(const Vector3 *direction);
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(const void *settings);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00120170 {
    char unknown_00[0xec];
    Vector3 eye;
    Vector3 target;

    void func_001202E0();
};

extern Device_00251D6C *data_00251D6C;
extern Game *data_0022FCE0;
extern unsigned char data_00225B18[];
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// Looks up object 0x1de2 (the result is not used), puts the eye at the origin and the target 3000 ahead, sets up the device (slot 30 with data_00225B18, slot 31
// with 0x18e3, 1 and 20000) and points the view through func_001BAF70.
void Object_00120170::func_001202E0()
{
    data_0022FCE0->func_000128C0(0x1de2);
    eye.x = 0;
    eye.y = 0;
    eye.z = 0;
    target.x = 0;
    target.y = 0;
    target.z = 3000.0f;
    data_00251D6C->slot30(data_00225B18);
    data_00251D6C->slot31(0x18e3, 1.0f, 20000.0f);
    func_001BAF70(&eye, &target, 0);
}
