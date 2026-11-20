/* sym: ?func_00011C80@Object_000FEDB0@@UAEXH@Z = 0x000FEDC0 */
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
    virtual void __stdcall slot30(const void *rect);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
};

struct Game {
    void func_00012750();
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The camera node (constructor func_00012170).
struct Object_00012170 : Node {
    char unknown_040[0x58];
};

// The child of the camera node whose table is at 0x1D1C30 (object 0x1163). Slot 3 is shared with the table at
// 0x1D1BF0 (object 0x1165, Object_000FDF30): the two overrides were folded.
struct Object_000FEDB0 : Object_00012170 {
    virtual void func_00011C80(int argument);
};

extern Device_00251D6C *data_00251D6C;
extern Game *data_0022FCE0;

// Slot 3: passes the screen rectangle (0, 0, 640, 480) to the device's slot 30 and (0x222, 1, 4000) to its slot
// 31, as func_001373A0 does, then calls func_00012750 of the game. The argument is not read.
void Object_000FEDB0::func_00011C80(int)
{
    int rect[4];
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 0x280;
    rect[3] = 0x1e0;
    data_00251D6C->slot30(rect);
    data_00251D6C->slot31(0x222, 1.0f, 4000.0f);
    data_0022FCE0->func_00012750();
}
