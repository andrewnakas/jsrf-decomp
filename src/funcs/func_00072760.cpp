/* sym: ?func_00011C80@Object_00072710@@UAEXH@Z = 0x00072760 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual long __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71(int texture);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74(int source, int destination);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82(int stage, int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_001FA1D0;
extern int data_00251D44;

// Hands `value` to the device slot when the cached state differs.
#define SET_STATE(cache, slot, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot(value); \
    }

// The class whose table is at 0x1CCAE0 (constructor 0x726A0, destructor 0x72710): overrides slots 1 (720B0) and
// 3 (72760).
struct Object_00072710 : Node {
    virtual ~Object_00072710();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    unsigned int state;
    char unknown_48[4];
    float heights[10];
    float alpha;
    float fade;

    void func_000723F0(unsigned int index, float x, float y, unsigned int colour);
    void func_000725B0(unsigned int colour);
};

// Slot 3: in states 1 to 5 (2 to 5 first cover the screen in black at the fade +0x78) draws the ten quads whose
// heights (+0x4c) lie between -1100 and 490 at x 64, white at the alpha +0x74, inside a device scene (slots 44 and
// 45) with alpha blending (slot 74: 0x302, 0x303).
void Object_00072710::func_00011C80(int)
{
    switch (state) {
    case 2:
    case 3:
    case 4:
    case 5:
        func_000725B0((unsigned char)fade << 24);
    case 1:
        SET_STATE(data_001FA1D0, slot73, 1);
        SET_STATE(data_001FA1CC, slot71, 0);
        if (data_00251D6C->slot44() < 0) {
            return;
        }
        if (data_00251D44 != 2) {
            data_00251D44 = 2;
            data_00251D6C->slot82(0, 2);
        }
        data_00251D6C->slot74(0x302, 0x303);
        for (unsigned int i = 0; i < 10; i++) {
            if (heights[i] > -1100.0f && heights[i] < 490.0f) {
                func_000723F0(i, 64.0f, heights[i], (unsigned char)alpha << 24 | 0xffffff);
            }
        }
        data_00251D6C->slot45();
        break;
    }
}
