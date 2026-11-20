/* sym: ?func_00011C80@Object_00067980@@UAEXH@Z = 0x00067310 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The Direct3D device.
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
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(const void *viewport);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
};

extern Device_00251D6C *data_00251D6C;

struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

struct Viewport_00067310 {
    int x;
    int y;
    int width;
    int height;
};

// The node 0x12af (table 0x1CB0F8, constructor 0x67B60, destructor 0x67980).
struct Object_00067980 : Node {
    virtual void func_00011C80(int argument);
};

// Slot 3 of the table at 0x1CB0F8: device state 33 to 0, the full 640 x 480 view (slot 30), slot 31 (0x222, 0.5,
// 4000), then the game's func_00012750.
void Object_00067980::func_00011C80(int argument)
{
    Viewport_00067310 viewport = {0, 0, 0x280, 0x1e0};
    data_00251D6C->slot33(0.0f);
    data_00251D6C->slot30(&viewport);
    data_00251D6C->slot31(0x222, 0.5f, 4000.0f);
    data_0022FCE0->func_00012750();
}
