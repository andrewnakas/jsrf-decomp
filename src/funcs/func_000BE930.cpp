/* sym: ?func_00011C80@Object_000BE900@@UAEXH@Z = 0x000BE930 */
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
    virtual long __stdcall slot31(long state, float first, float second);
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
    virtual long __stdcall slot42(int texture);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D88;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

struct Game {
    void func_00012750();
    void func_00012980();
};

extern Game *data_0022FCE0;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

extern Object_0006A960 data_0020C6C0;

struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

extern Object_00046670 data_001F93C8;

void func_001BA8A0();
void __fastcall func_001BB2E0(int angle);
void func_001BAA60(float x, float y, float z);
void func_001BB650(float distance);

// The owner (an Object_000BE1B0): its texture at 0x30c.
struct Owner_000BE930 {
    char unknown_000[0x30c];
    int texture;
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    Node *func_00011BD0();
};

// The child of Node whose table is at 0x1CDB60: overrides slots 2 and 3.
struct Object_000BE900 : Node {
    virtual ~Object_000BE900();
    virtual void func_00011C80(int message);

    char unknown_040[4];
    Vector3 position;
    char unknown_050[0x24];
    int fog;
};

// Slot 3: on message 0x13 it draws its view: the owner's texture (set on the device, slot 42, when it is not the
// current one in data_00251D88), func_00012980 of the game, fog 200..5000 (slot 31) from the value at 0x74, a camera
// a quarter turn down at the position, a range of 200, and the position handed to data_0020C6C0 and data_001F93C8.
void Object_000BE900::func_00011C80(int message)
{
    Owner_000BE930 *owner = (Owner_000BE930 *)func_00011BD0();
    if (message == 0x13) {
        if (data_00251D88 != data_00252790.func_0006E130(owner->texture)) {
            data_00251D88 = data_00252790.func_0006E130(owner->texture);
            data_00251D6C->slot42(data_00252790.func_0006E130(owner->texture));
        }
        data_0022FCE0->func_00012980();
        data_00251D6C->slot31(fog, 200.0f, 5000.0f);
        func_001BA8A0();
        func_001BB2E0(0x4000);
        func_001BAA60(-position.x, -position.y, -position.z);
        func_001BB650(200.0f);
        data_0020C6C0.func_0006A970(&position);
        data_001F93C8.func_00046670(&position);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
    }
}
